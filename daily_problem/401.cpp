#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    string s;
    map<char, int> pos;
    pos.clear();
    ll sum = 0;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (pos[s[i]] == 0)
        {
            sum += (len - i) * (i + 1);
            pos[s[i]] = i + 1;
        }
        else
        {
            sum += (i + 1 - pos[s[i]]) * (len - i);
            pos[s[i]] = i + 1;
        }
    }
    cout<<sum << endl;
    return 0;
}