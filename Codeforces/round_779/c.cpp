#include <bits/stdc++.h>
using namespace std;

int n;
int a[100010];
int flag;

void solve()
{
    cin >> n;
    flag = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            if (flag == 1)
            {
                flag = 0;
                break;
            }
            flag = 1;
        }
        if (i >= 2 && a[i] - a[i - 1] > 1)
        {
            flag = 0;
            break;
        }
    }
    if (n == 1 && a[1] == 1)
        flag = 1;
    if (a[1] - a[n] > 1)
        flag = 0;
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}
