#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int a[510][2];
map<pair<int, int>, int>s;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
void solve()
{
	int n;
	cin >> n;
	s.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			int x = a[j][0] - a[i][0];
			int y = a[j][1] - a[i][1];
			int g = gcd(x, y);
			if (s[make_pair(x / g, y / g)] == 0) {
				s[make_pair(x / g, y / g)] = 1;
				cnt++;
			}
		}
	}
	cout << cnt*2 << endl;//正反方向
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tt;
	tt = 1;
	while (tt--)solve();
	return 0;
}