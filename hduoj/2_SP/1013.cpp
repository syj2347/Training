//最短路径问题
#include <bits/stdc++.h>

using namespace std;

#define inf 2147483647
const int maxn = 5e5 + 5;
int n, m, s, e;
int cnt, head[maxn];
int dist[maxn], vis[maxn], ct[maxn];
struct edge
{
    int to, dis, next, cost;
} edge[maxn * 2];
void add(int from, int to, int w, int cost)
{
    edge[++cnt].to = to;
    edge[cnt].dis = w;
    edge[cnt].next = head[from];
    edge[cnt].cost = cost;
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
    ct[s] = 0;
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
            if (dist[now] + edge[i].dis < dist[j] || ((dist[now] + edge[i].dis == dist[j]) && (ct[j] > ct[now] + edge[i].cost)))
            {
                dist[j] = dist[now] + edge[i].dis;
                ct[j] = ct[now] + edge[i].cost;
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
    memset(ct, inf, sizeof(ct));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m, n || m)
    {
        init();
        while (m--)
        {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            add(a, b, x, y);
            add(b, a, x, y);
        }
        cin >> s >> e;
        Dij();
        cout << dist[e] << " " << ct[e] << "\n";
    }
    return 0;
}