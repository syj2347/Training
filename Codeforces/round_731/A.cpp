#define _CRT_SECURE_NO_WARNINGS 1
// Codeforces Round #731 (Div. 3)
// A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
	int xa, ya;
	int xb, yb;
	int a, b;
	cin >> xa >> ya;
	cin >> xb >> yb;
	cin >> a >> b;
	int ans = abs(xa - xb) + abs(ya - yb);
	int flag1 = 0;
	int flag2 = 0;
	if (b > min(ya, yb) && b < max(ya, yb))
		flag1 = 1;
	if (a > min(xa, xb) && a < max(xa, xb))
		flag2 = 1;
	if ((xa == xb && xa == a && flag1) || (ya == yb && ya == b && flag2))
	{
		ans += 2;
	}
	cout << ans << endl;
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