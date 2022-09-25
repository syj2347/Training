// Sudoku Killer
#include <bits/stdc++.h>

using namespace std;

typedef struct LNode
{
    int x;
    int y;
} node;
int mp[11][11];
node t[82];
int sum;
int flag;
int check(int num, int x, int y)
{
    for (int i = 0; i < 9; i++)
    {
        if (mp[x][i] == num || mp[i][y] == num)
            return 0;
    }
    for (int i = x / 3 * 3; i < x / 3 * 3 + 3; i++)
    {
        for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++)
        {
            if (x == i && y == j)
                continue;
            if (mp[i][j] == num)
                return 0;
        }
    }
    return 1;
}
void dfs(int k)
{
    if (k == sum)
    {
        for (int i = 0; i < 9; i++)
        {
            cout << mp[i][0];
            for (int j = 1; j < 9; j++)
            {
                cout << " " << mp[i][j];
            }
            flag = 1;
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (check(i, t[k].x, t[k].y))
        {
            mp[t[k].x][t[k].y] = i;
            dfs(k + 1);
            if (flag)
                return;
            mp[t[k].x][t[k].y] = -1;
        }
    }
}
int main()
{
    int k = 0;
    char s[3];
    while (cin >> s)
    {
        sum = 0;
        flag = 0;
        if (s[0] == '?')
        {
            t[sum].x = 0;
            t[sum].y = 0;
            mp[0][0] = -1;
            sum++;
        }
        else
        {
            mp[0][0] = s[0] - '0';
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                scanf("%s", s);
                if (s[0] == '?')
                {
                    t[sum].x = i;
                    t[sum].y = j;
                    sum++;
                    mp[i][j] = -1;
                }
                else
                    mp[i][j] = s[0] - '0';
            }
        }
        if (k)
            cout << endl;
        k++;
        dfs(0);
    }
    return 0;
}
