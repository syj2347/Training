#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	int flag = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[0] && i % 2 == 0) {
			flag = 1;
			break;
		}
	}
	if (flag)cout << "YES\n";
	else cout << "NO\n";
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