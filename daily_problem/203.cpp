#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans[i] = a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] >= a[j])
            {
                ans[i] = max(ans[i], ans[j] + a[i]);
            }
        }
    }
    int Max = -1;
    for (int i = 1; i <= n; i++)
    {
        Max = max(Max, ans[i]);
        // cout << ans[i] << " ";
    }
    // cout << "\n";
    cout << Max << endl;
    return 0;
}