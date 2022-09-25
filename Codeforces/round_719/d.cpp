#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void solve()
{
    int n;
    map<ll, ll> s;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[a[i] - i]++;
    }
    ll ans = 0;
    for (auto x : s)
    {
        if (x.second % 2 == 0)
            ans += (x.second / 2 * (x.second - 1));
        else
            ans += (x.second * ((x.second - 1) / 2));
    }
    cout << ans << endl;
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