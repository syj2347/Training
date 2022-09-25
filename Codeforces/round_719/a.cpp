#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    string s;
    map<char, int> o;
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (o[s[i]])
        {
            if (s[i - 1] != s[i])
            {
                cout << "NO\n";
                return;
            }
        }
        else
            o[s[i]] = 1;
    }
    cout << "YES\n";
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