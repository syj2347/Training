#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << "-1\n";
        return;
    }
    if (n == 3)
    {
        cout << "8 5 3\n4 2 7\n1 6 9\n";
        return;
    }
    int cnt = 1;
    int Map[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j += 2, cnt++)
            Map[i][j] = cnt;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= n; j += 2, cnt++)
            Map[i][j] = cnt;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << Map[i][j] << " ";
        cout << "\n";
    }
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