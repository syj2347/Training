#define _CRT_SECURE_NO_WARNINGS 1
//C

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int a[110];
int b[110];
int ans[220];
void solve()
{
	int k, n, m;
	cin >> k >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	int ai = 1, bi = 1;
	int p = k;
	int flag = 0;
	int cnt = 1;
	while (1) {
		if (ai > n && bi > m)break;
		if (ai<=n&&a[ai] == 0) {
			ans[cnt] = 0;
			cnt++;
			p++;
			ai++;
			continue;
		}
		if (bi<=m&&b[bi] == 0) {
			ans[cnt] = 0;
			cnt++;
			p++;
			bi++;
			continue;
		}
		if (ai<=n&&a[ai] <= p) {
			ans[cnt] = a[ai];
			cnt++;
			ai++;
			continue;
		}
		if (bi<=m&&b[bi] <= p) {
			ans[cnt] = b[bi];
			cnt++;
			bi++;
			continue;
		}
		flag = 1;
		break;
	}
	if (flag)cout << "-1\n";
	else {
		for (int i = 1; i <= cnt - 1; i++)
			cout << ans[i] << " ";
	}
	cout << "\n";

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