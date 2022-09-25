#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    map<int, int> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[a[i]] = 1;
    }
    for (auto &i : s)
    {
        if (s.count(i.first + k))
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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



