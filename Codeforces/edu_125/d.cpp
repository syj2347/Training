#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n, C;
    cin >> n >> C;
    vector<ll> cost(C + 1);
    for (int i = 1; i <= n; ++i)
    {
        ll c, d, h;
        cin >> c >> d >> h;
        cost[c] = max(d * h, cost[c]);
    }
    for (int i = 1; i <= C; i++)
    {
        for (int j = i; j <= C; j += i)
        {
            cost[j] = max(cost[j], j / i * cost[i]);
        }
    }
    for (int i = 1; i <= C; i++)
        cost[i] = max(cost[i], cost[i - 1]);
    ll m;
    cin >> m;
    vector<ll> ans;
    while (m--)
    {
        ll d, h;
        cin >> d >> h;
        if (d * h >= cost[C])
            ans.push_back(-1);
        else
        {
            ans.push_back(upper_bound(cost.begin() + 1, cost.begin() + C + 1, d * h) - cost.begin());
        }
    }
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    // cin >> tt;
    tt = 1;
    while (tt--)
        solve();
    return 0;
}