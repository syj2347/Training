#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt = count(s.begin(), s.end(), '*');
    int l = 0;
    ll ans = 0;
    for (auto c : s)
    {
        if (c == '*')
            l++;
        else
            ans += min(l, cnt - l);
    }
    cout << ans << endl;
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
