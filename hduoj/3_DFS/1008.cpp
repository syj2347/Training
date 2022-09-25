// Sudoku
// unsolved
#include <bits/stdc++.h>

using namespace std;

char arr[5][5];
int col[5][5];
int row[5][5];
int four[5][5];
int k;
int flag;
struct Node
{
    int x;
    int y;
} node[20];
void deal(int i, int j, int x, int num)
{
    row[i][x] = num;
    col[j][x] = num;
    if (i <= 2 && j <= 2)
        four[1][x] = num;
    if (i <= 2 && j > 2)
        four[2][x] = num;
    if (i > 2 && j <= 2)
        four[3][x] = num;
    if (i > 2 && j > 2)
        four[4][x] = num;
}

int check(int i, int j, int x)
{
    if (row[i][x] == 1 || col[j][x] == 1)
        return 0;
    if (i <= 2 && j <= 2 && four[1][x] == 1)
        return 0;
    if (i <= 2 && j > 2 && four[2][x] == 1)
        return 0;
    if (i > 2 && j <= 2 && four[3][x] == 1)
        return 0;
    if (i > 2 && j > 2 && four[4][x] == 1)
        return 0;
    return 1;
}
void dfs(int cnt)
{
    if (cnt == k)
        flag = 0;
    int x = node[cnt].x;
    int y = node[cnt].y;
    for (int i = 1; i <= 4 && flag; i++)
    {
        if (check(x, y, i))
        {
            deal(x, y, i, 1);
            arr[x][y] = i + '0';
            dfs(cnt + 1);
            deal(x, y, i, 0);
        }
    }
}
void init()
{
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    memset(four, 0, sizeof(four));
}
int main()
{
    int n;
    cin >> n;
    for (int m = 1; m <= n; m++)
    {
        k = 0;
        flag = 1;
        init();
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                cin >> arr[i][j];
                char x = arr[i][j];
                if (x != '*')
                    deal(i, j, x - '0', 1);
                else
                {
                    node[k].x = i;
                    node[k++].y = j;
                }
            }
        }
        dfs(0);
        cout << "Case #" << m << ":\n";
        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
                cout << arr[i][j];
            cout << "\n";
        }
    }
    return 0;
}
