#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    string s;
    int cnt = 0;

    cin >> n >> s;
    char temp = s[0];
    int t = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != temp && s[i] == ')')
        {
            int k = t, j = i;
            int flag = 0;
            while (k <= j)
            {
                if (s[k++] == s[j--])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            cnt++;
            t = i + 1;
            temp = s[t];
            i = t;
            continue;
        }
        else if (s[i] == temp)
        {
            int flag = 0;
            int k = t, j = i;
            while (k <= j)
            {
                if (s[k++] != s[j--])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            cnt++;
            t = i + 1;
            temp = s[t];
            i = t;
        }
    }
    cout << cnt << " " << n - t << endl;
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