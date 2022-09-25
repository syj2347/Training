#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j)
            a[i][j] = s[j-1] - '0';
    }
    if (a[1][1] == 1) {
        cout << -1 << '\n';
        return;
    }
    cout << n * m << endl;
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (a[i][j]) {
                if (j > 1)cout << i << " " << j - 1 << " " << i << " " << j << "\n";
                else {
                    cout << i-1 << " " << j << " " << i << " " << j << "\n";
                }
            }
            else { 
                cout << i << " " << j << " " << i << " " << j << "\n";
            }
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tt;
	cin >> tt;
	while (tt--)solve();
	return 0;
}