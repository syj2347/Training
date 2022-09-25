//迷宫城堡
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int maxm = 5e5 + 5;
int n, m;
int u[maxn], v[maxn];
bool vis[maxn];
int belong[maxn]; 
int out[maxn];
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
void init()
{
    cnt = 0;
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
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
            add(belong[u[i]], belong[v[i]]);
}
int main()
{
    while (cin >> n >> m, n || m)
    {
        init();
        memset(out, 0, sizeof(out));
        for (int i = 1; i <= m; i++)
        {
            cin >> u[i] >> v[i];
            add1(u[i], v[i]);
            add2(v[i], u[i]);
        }
        // build();
        scc_cnt = scc();
        if (scc_cnt == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
