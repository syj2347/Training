#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> mp;

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        sum += x;
    }

    queue<ll> q;
    q.push(sum);

    for (int i = 1; i <= 2*n && q.size(); i++)
    {
        sum = q.front();
        q.pop();
        if (mp[sum])
            mp[sum]--;
        else
        {
            q.push(sum / 2);
            q.push((sum + 1) / 2);
        }
    }

    if (q.size() == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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

// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// int flag;
// map<ll, ll> vis;
// vector<ll> a;
// int n;

// void dfs(ll cnt)
// {
//     if (cnt == n - 1)
//     {
//         flag = 1;
//         return;
//     }
//     if (flag)
//         return;
//     ll len = a.size();
//     for (ll i = 0; i < len; i++)
//     {
//         if (flag)
//             return;
//         if (vis[i] == 0)
//         {
//             for (ll j = i + 1; j < len; j++)
//             {
//                 if (flag)
//                     return;
//                 if (j == i)
//                     continue;
//                 if (vis[j])
//                     continue;
//                 ll mid = (a[i] + a[j]) / 2;
//                 if (mid == a[i] || mid == a[j])
//                 {
//                     a.push_back(a[i] + a[j]);
//                     vis[i] = 1;
//                     vis[j] = 1;
//                     dfs(cnt + 1);
//                     vis[i] = 0;
//                     vis[j] = 0;
//                     a.pop_back();
//                 }
//             }
//         }
//     }
//     return;
// }

// void solve()
// {
//     vis.clear();
//     a.clear();
//     flag = 0;
//     cin >> n;

//     for (ll i = 1; i <= n; i++)
//     {
//         ll x;
//         cin >> x;
//         a.push_back(x);
//     }
//     dfs(0);

//     if (flag)
//         cout << "YES\n";
//     else
//         cout << "NO\n";
//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int tt;
//     cin >> tt;
//     while (tt--)
//         solve();
//     return 0;
// }