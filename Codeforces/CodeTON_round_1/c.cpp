#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            flag = 1;
    }
    if (flag == 0)
    {
        cout << "YES\n";
        return;
    }
    sort(a.begin(), a.end());
    int temp = a[0];
    for (auto x : a)
    {
        if (x == temp + 1)
        {
            flag = 0;
            break;
        }
        temp = x;
    }
    if (flag)
    {
        cout << "YES\n";
    }
    else
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