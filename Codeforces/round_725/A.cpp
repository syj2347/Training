#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int a[110];
void solve()
{
	int n;
	cin >> n;
	int Max = -1;
	int Min = 1000;
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > Max)
		{
			Max = a[i];
			temp1 = i;
		}
		if (a[i] < Min)
		{
			Min = a[i];
			temp2 = i;
		}
	}
	int ans;
	if (temp1 <= temp2)
	{
		ans = min(min(temp2, n - temp1 + 1), temp1 + n - temp2 + 1);
		cout << ans << "\n";
		return;
	}
	else
	{
		ans = min(min(temp1, n - temp2 + 1), temp2 + n - temp1 + 1);
		cout << ans << "\n";
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