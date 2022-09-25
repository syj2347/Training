// unsolved
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int d = 1e9 + 7;

void solve()
{
    string s;
    vector<int> cnt(20);
    ll m;
    ll ans = 0;

    cin >> s >> m;
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - '0']++;
    }
    for (int i = 1; i <= m; i++)
    {
        ll x[10];
        for (int j = 0; j <= 9; j++)
            x[j] = cnt[j];
        ans += x[9];
        for (int j = 0; j <= 9; j++)
        {
            if (cnt[j] == 0)
                continue;
            if (j == 0)
            {
                cnt[j] += x[9];
                cnt[1] += x[9];
                continue;
            }
            cnt[j] += x[j - 1];
        }
    }
    cout << ans + s.size() << "\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}