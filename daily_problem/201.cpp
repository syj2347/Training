#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    map<pair<int, int>, int> a;
    map<pair<int, int>, int> b;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        a[make_pair(s, e)] = max(a[make_pair(s, e)], w);
        b[make_pair(s, e)] = max(b[make_pair(s, e)], w);
    }

    map<pair<int, int>, int>::iterator i, j;
    for (i = a.begin(); i != a.end(); i++)
        for (j = a.begin(); j != i; j++)
            if (i->first.first >= j->first.second)
            {
                i->second = max(i->second, j->second + b[make_pair(i->first.first, i->first.second)]);
            }

    int Max = -1;
    for (i = a.begin(); i != a.end(); i++)
        Max = max(Max, i->second);
    cout << Max << endl;
    return 0;
}