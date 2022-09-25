#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i)
    {
        string left = s.substr(0, i + 1);
        string right = s.substr(i + 1, n - i - 1);
        reverse(left.begin(), left.end());
        reverse(right.begin(), right.end());
        if (left + right == s)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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