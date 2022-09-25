// Kosaraju
//unsolved
#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 7;
int V;
int cost[maxn], vis[maxn], group[maxn], in[maxn];
int mincost[maxn];
vector<int> G[maxn];
vector<int> rG[maxn];
vector<int> q;
vector<int> sG[maxn];

void add(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs1(int v)
{
    vis[v] = true;
    for (int i = 0; i < (int)G[v].size(); ++i)
        if (!vis[G[v][i]])
            dfs1(G[v][i]);
    q.push_back(v);
}

void dfs2(int v, int k)
{
    vis[v] = true;
    group[v] = k;
    cost[k]++;
    for (int i = 0; i < (int)rG[v].size(); ++i)
        if (!vis[rG[v][i]])
            dfs2(rG[v][i], k);
}

int scc()
{
    memset(vis, 0, sizeof(vis));
    q.clear();
    for (int i = 0; i < V; ++i)
        if (!vis[i])
            dfs1(i);

    int k = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = q.size() - 1; i >= 0; --i)
        if (!vis[q[i]])
            dfs2(q[i], k++);
    return k;
}
void build()
{
    memset(in, 0, sizeof(in));

    for (int v = 0; v < V; ++v)
    {
        for (int i = 0; i < (int)G[v].size(); ++i)
        {
            if (group[v] == group[G[v][i]])
                continue;
            sG[group[v]].push_back(group[G[v][i]]);
            //cout << "t:" << v << "-" << G[v][i] << "\n";
            in[group[G[v][i]]]++;
        }
    }
}
void dfs(int v)
{
    for (int i = 0; i < (int)sG[v].size(); ++i)
    {
        //cout << "t:" << v << "::" << sG[v][i] << "\n";
        cost[sG[v][i]] += cost[v];
        dfs(sG[v][i]);
    }
}
void init()
{
    for (int i = 0; i < V; ++i)
    {
        G[i].clear();
        rG[i].clear();
        sG[i].clear();
    }
    memset(cost, 0, sizeof(cost));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int tt;
    cin >> tt;
    int id = 1;
    while (tt--)
    {
        cin >> n >> m;
        V = n;
        int x, y;
        init();
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            add(x, y);
        }
        int N = scc();
        build();
        // for (int i = 0; i < N; ++i)
        //     cout << "t:" << i << " " << cost[i] << "\n";
        // for (int i = 0; i < N; ++i)
        //     cout << "in:" << i << " " << in[i] << "\n";
        for (int i = 0; i < N; i++)
            if (in[i] == 0)
                dfs(i);
        int Max = -1;
        int p = -1;
        for (int i = 0; i < N; i++)
        {
            //cout << "t:" << i << " " << cost[i] << "\n";
            if (Max < cost[i])
            {
                Max = cost[i];
                p = i;
            }
        }
        vector<int> xx;
        for (int i = 0; i < V; i++)
            if (cost[group[i]] == Max)
                xx.push_back(i);
        cout << "Case " << id << ": " << Max - 1 << "\n";
        for (auto e : xx)
            cout << e << " ";
        cout << "\n";
        id++;
    }
    return 0;
}