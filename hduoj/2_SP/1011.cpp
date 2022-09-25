// Einbahnstrasse
#include <bits/stdc++.h>

using namespace std;

int n, m, s, e;
int Map[110][110];
void floyd()
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
}
void init()
{

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                Map[i][j] = 0;
            else
                Map[i][j] = 0x3f3f3f3f;
        }
}
int main()
{
    int ct = 0;
    int p;
    while (cin >> n >> p >> m, n || p || m)
    {
        ct++;
        int ans = 0;
        init();
        map<string, int> o;
        string name[1010];
        int temp = p;
        p++;
        int q = 0;
        for (int i = 1; i <= p; i++)
        {
            cin >> name[i];
            if (o[name[i]] == 0)
                o[name[i]] = i - q;
            else
                q++;
            // cout << "t:" << name[i] << " " << o[name[i]] << endl;
        }
        while (m--)
        {
            string fr, b, to;
            int num;
            char x, y;
            cin >> fr;
            scanf(" %c-%d-%c ", &x, &num, &y);
            cin >> to;
            if (o[fr] == 0)
            {
                p++;
                o[fr] = p - q;
            }
            if (o[to] == 0)
            {
                p++;
                o[to] = p - q;
            }
            int f = o[fr];
            int t = o[to];
            if (x == '<')
            {
                Map[t][f] = min(Map[t][f], num);
                // cout << "t:" << t << " " << f << " " << Map[t][f] << "\n";
            }
            if (y == '>')
            {
                Map[f][t] = min(Map[f][t], num);
                // cout << "t:" << f << " " << t << " " << Map[f][t] << "\n";
            }
        }
        floyd();
        for (int i = 2; i <= temp + 1; i++)
        {
            // cout << "t:" << i << " " << Map[i][1] << "\n";
            ans += (Map[1][o[name[i]]] + Map[o[name[i]]][1]);
            // cout << "t:" << o[name[i]] << " " << ans << "\n";
        }
        cout << ct << ". " << ans << "\n";
    }
    return 0;
}