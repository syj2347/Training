#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
ll n;

void solve()
{
	ll l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a , a + n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (upper_bound(a + i + 1, a + n, r - a[i]) - lower_bound(a + i + 1, a + n, l - a[i]));
	}
	cout << ans << "\n";
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
