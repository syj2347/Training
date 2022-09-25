// In Action
#include <bits/stdc++.h>

using namespace std;

#define inf 2147483647
const int maxn = 5e5 + 5;
int n, m, s;
int cnt, head[maxn];
int dist[maxn], vis[maxn];
int ss[maxn];
int f[maxn];
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
    memset(ss, 0, sizeof(ss));
    memset(f, 0, sizeof(f));
}
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> m;
        init();
        while (m--)
        {
            int a, b, x;
            cin >> a >> b >> x;
            add(a, b, x);
            add(b, a, x);
        }
        int v = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> ss[i];
            v += ss[i];
        }
        s = 0;
        Dij();
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            //cout << "t:" << i << " " << dist[i] << endl;
            if (dist[i] == inf)
                continue;
            sum += dist[i];
        }
        for (int i = 1; i <= n; i++)
            for (int j = sum; j >= dist[i]; j--)
                f[j] = max(f[j], f[j - dist[i]] + ss[i]);
        int flag = 0;
        int ans;
        for (int i = 0; i < sum; i++)
        {
            if (f[i] > v / 2)
            {
                flag = 1;
                ans = i;
                break;
            }
        }
        if (flag == 0)
            cout << "impossible\n";
        else
            cout << ans << "\n";
    }
    return 0;
}