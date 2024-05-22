#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
class Point
{
public:
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator<(const Point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};
int n, k, m, cnt;
vector<vector<int>> a;
vector<vector<bool>> visited;
vector<Point> sleeps;
map<pair<Point, Point>, int> dist;
bool isSafe(int x, int y)
{
    if (x >= 1 && y >= 1 && x <= n && y <= n)
        return true;
    return false;
}
void DFS(Point u)
{
    if (a[u.x][u.y])
        cnt++;
    visited[u.x][u.y] = true;
    for (int i = 0; i < 4; i++)
    {
        int x = u.x + dx[i];
        int y = u.y + dy[i];
        Point v = Point(x, y);
        if (isSafe(x, y) && !visited[x][y] && !dist[{u, v}])
            DFS(v);
    }
}
void solve()
{
    cnt = 0;
    cin >> n >> k >> m;
    a.assign(n + 5, vector<int>(m + 5, 0));
    visited.assign(n + 5, vector<bool>(m + 5, false));
    for (int i = 0; i < m; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        dist[{Point(u, v), Point(x, y)}] = 1;
        dist[{Point(x, y), Point(u, v)}] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        sleeps.push_back(Point(x, y));
        a[x][y] = 1;
    }
    int tmp = 0, res = 0;
    for (int i = 0; i < k; i++)
        if (!visited[sleeps[i].x][sleeps[i].y])
        {
            DFS(sleeps[i]);
            res += tmp * cnt;
            tmp += cnt;
            cnt = 0;
        }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}