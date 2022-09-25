#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll a[10010];
int cnt;
void init()
{
    cnt = 0;
    for (int i = 1; i <= 9; i++)
    {
        ll p = i;
        while (p <= 1000000000)
        {
            cnt++;
            a[cnt] = p;
            p = p * 10 + i;
        }
    }
    sort(a + 1, a + cnt + 1);
}
void solve()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= cnt; i++)
    {
        if (a[i] > n)
        {
            cout << i - 1 << endl;
            return;
        }
    }
    cout << cnt << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}