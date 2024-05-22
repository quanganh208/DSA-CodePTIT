#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
struct Position
{
    int x, y, z, dist;
};
int bfs(vector<vector<vector<char>>> &grid, int A, int B, int C, Position start)
{
    queue<Position> q;
    q.push(start);
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    visited[start.x][start.y][start.z] = true;
    while (!q.empty())
    {
        Position cur = q.front();
        q.pop();
        if (grid[cur.x][cur.y][cur.z] == 'E')
            return cur.dist;
        for (int i = 0; i < 6; ++i)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < A && ny < B && nz < C && !visited[nx][ny][nz] && grid[nx][ny][nz] != '#')
            {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, cur.dist + 1});
            }
        }
    }
    return -1;
}
void solve()
{
    int A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<char>>> grid(A, vector<vector<char>>(B, vector<char>(C)));
    Position start;
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            for (int k = 0; k < C; k++)
            {
                cin >> grid[i][j][k];
                if (grid[i][j][k] == 'S')
                    start = {i, j, k, 0};
            }
    cout << bfs(grid, A, B, C, start) << endl;
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