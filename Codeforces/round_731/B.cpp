#define _CRT_SECURE_NO_WARNINGS 1
//B
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, int>a;
void solve()
{
	string s;
	cin >> s;
	int flag = 0;
	a.clear();
	int Max = 0;
	for (int i = 0; i < s.size(); i++) {
		Max = max(Max, s[i] - 'a');
		a[s[i]-'a']++;
		if (a[s[i]-'a'] > 1) {
			flag = 1;
			break;
		}
		if (i == 0 || i == s.size()-1)continue;
		if (s[i] > s[i + 1] && s[i] > s[i - 1]) {
			flag = 1;
			break;
		}
	}
	for (int i = 0; i <= Max; i++) {
		if (a[i] != 1) {
			flag = 1;
			break;
		}
	}
	if (flag)cout << "NO\n";
	else cout << "YES\n";
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