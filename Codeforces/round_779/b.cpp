#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll d = 998244353;

void solve()
{
    ll n;
    cin >> n;
    ll ans = 1;
    if (n % 2)
    {
        cout << "0\n";
        return;
    }
    ll k = n / 2;
    for (int j = k; j >= 1; j--)
    {
        ans = (ans % d) * (j % d) % d;
    }
    ans = (ans % d) * (ans % d) % d;
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