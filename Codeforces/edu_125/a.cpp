#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int a[5000];
void init()
{
    for (int i = 0; i * i <= 5000; i++)
        a[i * i] = 1;
}
void solve()
{
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0)
    {
        cout << "0\n";
        return;
    }
    if (a[x * x + y * y])
    {
        cout << "1\n";
        return;
    }
    cout << "2\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}