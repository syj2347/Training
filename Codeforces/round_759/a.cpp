#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 && a[i - 1] == 1)
        {
            ans += 5;
            continue;
        }
        if (a[i] == 1)
        {
            ans += 1;
            continue;
        }
        if (a[i] == 0 && a[i - 1] == 0 && i >= 2)
        {
            ans = -1;
            break;
        }
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