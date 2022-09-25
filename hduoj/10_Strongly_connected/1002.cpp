// Summer Holiday
// tle
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5;
const int maxm = 2e3 + 5;
const int inf = 0x3f3f3f3f;
int n, m;
int u[maxm], v[maxm];
bool vis[maxn];
int belong[maxn];
struct Edge
{
    int to;
    int next;
} edge[maxm * 2];
int cnt;
int head1[maxn];
int head2[maxn];
int head[maxn];
int scc_cnt;
stack<int> Q;
int cost[maxn];
int mincost[maxn];
int o[maxn];

void init()
{
    cnt = 0;
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    memset(o, 0, sizeof(o));
}
void add(int u, int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
void add1(int u, int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head1[u];
    head1[u] = cnt;
}
void add2(int u, int v)
{
    edge[++cnt].to = v;
    edge[cnt].next = head2[u];
    head2[u] = cnt;
}
void dfs1(int u)
{
    vis[u] = 1;
    for (int k = head1[u]; ~k; k = edge[k].next)
    {
        int v = edge[k].to;
        if (!vis[v])
            dfs1(v);
    }
    Q.push(u);
}
void dfs2(int u, int group)
{
    vis[u] = 1;
    belong[u] = group;
    for (int k = head2[u]; ~k; k = edge[k].next)
    {
        int v = edge[k].to;
        if (!vis[v])
            dfs2(v, group);
    }
}
int scc()
{
    int ans = 0;
    memset(vis, 0, sizeof(vis));
    while (!Q.empty())
        Q.pop();
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs1(i);
    }
    memset(vis, 0, sizeof(vis));
    while (!Q.empty())
    {
        int x = Q.top();
        Q.pop();
        if (!vis[x])
        {
            ans++;
            dfs2(x, ans);
        }
    }
    return ans;
}
void build()
{
    cnt = 1;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++)
        if (belong[u[i]] != belong[v[i]])
        {
            o[belong[v[i]]] = 1;
            // add(belong[u[i]], belong[v[i]]);
        }
}
int main()
{
    while (cin >> n >> m)
    {
        init();
        memset(cost, 0, sizeof(cost));
        memset(mincost, inf, sizeof(mincost));
        for (int i = 1; i <= n; i++)
            cin >> cost[i];
        for (int i = 1; i <= m; i++)
        {
            cin >> u[i] >> v[i];
            add1(u[i], v[i]);
            add2(v[i], u[i]);
        }
        scc_cnt = scc();
        for (int i = 1; i <= n; i++)
            mincost[belong[i]] = min(mincost[belong[i]], cost[i]);
        build();
        int sum = 0;
        int ct = 0;
        for (int i = 1; i <= scc_cnt; i++)
        {
            if (o[i])
                continue;
            ct++;
            sum += mincost[i];
        }
        cout << ct << " " << sum << endl;
    }
    return 0;
}