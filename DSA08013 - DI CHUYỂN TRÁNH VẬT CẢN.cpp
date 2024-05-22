#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int N;
struct Point
{
    int x, y, dist;
};
bool isValid(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == '.' && !visited[x][y]);
}
int bfs(int startX, int startY, int endX, int endY)
{
    queue<Point> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        Point p = q.front();
        q.pop();
        if (p.x == endX && p.y == endY)
            return p.dist;
        for (int i = 0; i < 4; i++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            while (isValid(nx, ny))
            {
                visited[nx][ny] = true;
                q.push({nx, ny, p.dist + 1});
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    return -1; // Không tìm thấy đường đi
}
void solve()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> grid[i];
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    memset(visited, false, sizeof(visited));
    cout << bfs(a, b, c, d) << endl;
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