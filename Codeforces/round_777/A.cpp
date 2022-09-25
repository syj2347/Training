#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
	int n;
	cin >> n;
	if (n % 3 == 0) {
		int d = n / 3;
		while (d--) {
			cout << "21";
		}
		cout << "\n";
		return;
	}
	else if (n % 3 == 1) {
		int d = n / 3;
		cout << "1";
		while (d--)
			cout << "21";
		cout << "\n";
		return;
	}
	else {
		int d = n / 3;
		cout << "2";
		while (d--)
			cout << "12";
		cout << "\n";
		return;
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