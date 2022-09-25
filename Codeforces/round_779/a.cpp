#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
int a[1010];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    int cnt1 = 0;
    int t;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            break;
        if (s[i] == '0')
        {
            cnt1 = 0;
            i++;
            while (s[i] == '1')
            {
                cnt1++;
                i++;
            }
            if (i == n)
                break;
            if (cnt1 >= 2)
            {
                i--;
                continue;
            }
            else
            {
                i--;
                cnt += (2 - cnt1);
                continue;
            }
        }
    }
    cout << cnt << endl;
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