#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> cnt;

ll d(ll x)
{
    if (!x)
        return 0;
    if (cnt[x])
    {
        cnt[x]--;
        return 1;
    }
    return d(x / 2) && d((x + 1) / 2);
}
int main()
{
    ll tt;
    cin >> tt;
    while (tt--)
    {
        ll n;
        ll sum = 0;
        cin >> n;
        cnt.clear();
        for (int i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            cnt[x]++;
            sum += x;
        }
        puts(d(sum) ? "YES" : "NO");
    }
}
