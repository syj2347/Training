#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, b, x, y;
ll t;

void ch()
{
    if (b - t >= x)
        t += x;
    else
        t -= y;
    return;
}
void solve()
{
    cin >> n >> b >> x >> y;
    ll ans = 0;
    t = 0;
    for (int i = 1; i <= n; i++)
    {
        ch();
        ans += t;
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