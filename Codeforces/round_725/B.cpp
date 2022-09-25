#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int a[N];
void solve()
{
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n)
	{
		cout << "-1\n";
		return;
	}
	sum /= n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > sum)
			ans++;
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