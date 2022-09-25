#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int f(int x, int a)
{
	return x / a + x % a;
}
void solve()
{
	int l, r, a;
	cin >> l >> r >> a;
	if (r - r % a - 1 >= l) {
		cout << max(f(r, a), f(r - r % a - 1, a)) << endl;
	}
	else cout << f(r, a) << endl;
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