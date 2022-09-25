#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s[a[i]] = i;
    }
    sort(a.begin(), a.end());
    cout << s[a[0]] + 1 << " " << s[a[n - 1]] + 1 << "\n";
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