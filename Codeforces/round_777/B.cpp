#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int Map[110][110];

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			Map[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n-1; i++) {
		for (int j = 1; j <= m-1; j++) {
			int sum = Map[i][j] + Map[i + 1][j] + Map[i][j + 1] + Map[i + 1][j + 1];
			if (sum == 3) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
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