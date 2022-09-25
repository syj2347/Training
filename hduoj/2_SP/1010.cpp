// Here We Go(relians) Again
#include <bits/stdc++.h>

using namespace std;

#define inf 2147483647
const int maxn = 5e5 + 5;
int n, m, s, e;
int cnt, head[maxn];
int dist[maxn], vis[maxn];
struct edge
{
    int to, dis, next;
} edge[maxn * 2];
void add(int from, int to, int w)
{
    edge[++cnt].to = to;
    edge[cnt].dis = w;
    edge[cnt].next = head[from];
    head[from] = cnt;
}
struct node
{
    int id, dis;
    bool operator<(const node &a) const { return a.dis < dis; }
};
void Dij()
{
    priority_queue<node> q;
    q.push(node{s, 0});
    for (int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[s] = 0;
    while (!q.empty())
    {
        node a = q.top();
        q.pop();
        int now = a.id;
        if (vis[now])
            continue;
        vis[now] = 1;
        for (int i = head[now]; i; i = edge[i].next)
        {
            int j = edge[i].to;
            if (dist[now] + edge[i].dis < dist[j])
            {
                dist[j] = dist[now] + edge[i].dis;
                q.push(node{j, dist[j]});
            }
        }
    }
}
void init()
{
    cnt = 0;
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
}
int main()
{
    int n0, m0;
    while (cin >> n0 >> m0, n0 || m0)
    {
        n = (m0 + 1) * (n0 + 1);
        init();
        for (int i = 1; i <= 2 * n0 + 1; i++)
        {
            if (i % 2)
            {
                for (int j = 1; j <= m0; j++)
                {
                    int a;
                    char dir;
                    cin >> a >> dir;
                    if (a == 0)
                        continue;
                    a = 2520 / a;
                    int fr, to;
                    int r = i / 2 + 1;
                    fr = (m0 + 1) * (r - 1) + j;
                    to = (m0 + 1) * (r - 1) + j + 1;
                    // cout << "test:" << fr << " " << to << " " << a << "\n";
                    if (dir == '*')
                    {
                        add(fr, to, a);
                        add(to, fr, a);
                    }
                    else if (dir == '>')
                        add(fr, to, a);
                    else if (dir == '<')
                        add(to, fr, a);
                }
            }
            else
            {
                for (int j = 1; j <= m0 + 1; j++)
                {
                    int a;
                    char dir;
                    cin >> a >> dir;
                    if (a == 0)
                        continue;
                    a = 2520 / a;
                    int fr, to;
                    int r = i / 2;
                    fr = (m0 + 1) * (r - 1) + j;
                    to = (m0 + 1) * r + j;
                    // cout << "test:" << fr << " " << to << " " << a << "\n";
                    if (dir == '*')
                    {
                        add(fr, to, a);
                        add(to, fr, a);
                    }
                    else if (dir == 'v')
                        add(fr, to, a);
                    else if (dir == '^')
                        add(to, fr, a);
                }
            }
        }
        s = 1, e = n;
        // cout << "se:" << s << " " << e << endl;
        Dij();
        if (dist[e] != inf)
            cout << dist[e] << " blips\n";
        else
            cout << "Holiday\n";
    }
    return 0;
}