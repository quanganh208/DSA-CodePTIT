#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y)
{
    int n = grid.size();
    int m = grid[0].size();
    visited[x][y] = true;
    // Directions: right, left, down, up, top-right, top-left, bottom-right, bottom-left
    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
    for (int i = 0; i < 8; ++i)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && grid[newX][newY] == 'W')
            dfs(grid, visited, newX, newY);
    }
}
int countPonds(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int pondCount = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 'W' && !visited[i][j])
            {
                dfs(grid, visited, i, j);
                pondCount++;
            }
    return pondCount;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    cout << countPonds(grid) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}