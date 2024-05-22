#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, m;
char a[501][501];
int start_x, start_y;
int end_x, end_y;
bool flag;
void DFS(int x, int y, int parent, int count)
{
    if (count > 3)
        return;
    if (x == end_x && y == end_y)
    {
        flag = true;
        return;
    }
    a[x][y] = '*';
    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && a[new_x][new_y] != '*')
        {
            if (i == parent)
                DFS(new_x, new_y, parent, count);
            else
                DFS(new_x, new_y, i, count + 1);
        }
    }
    a[x][y] = '.';
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
            {
                start_x = i;
                start_y = j;
            }
            if (a[i][j] == 'T')
            {
                end_x = i;
                end_y = j;
            }
        }
    flag = false;
    DFS(start_x, start_y, -1, 0);
    cout << (flag ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}