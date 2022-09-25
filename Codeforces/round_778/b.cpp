#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    map<char, int> a;
    int t = s.size() - 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (a[s[i]] == 0)
        {
            a[s[i]] = 1;
            t = i;
        }
    }
    for (int i = t; i < s.size(); i++)
        cout << s[i];
    cout << "\n";
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