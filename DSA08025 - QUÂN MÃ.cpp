#include <bits/stdc++.h>
using namespace std;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isValid(int x, int y)
{
    return x >= 0 and x < 8 and y >= 0 and y < 8;
}
int minMoves(pair<int, int> start, pair<int, int> end)
{
    queue<pair<pair<int, int>, int>> q;
    bool visited[8][8];
    memset(visited, false, sizeof(visited));
    q.push({start, 0});
    visited[start.first][start.second] = true;
    while (!q.empty())
    {
        pair<pair<int, int>, int> current = q.front();
        q.pop();
        if (current.first == end)
            return current.second;
        for (int i = 0; i < 8; i++)
        {
            int nx = current.first.first + dx[i];
            int ny = current.first.second + dy[i];
            if (isValid(nx, ny) and !visited[nx][ny])
            {
                q.push({{nx, ny}, current.second + 1});
                visited[nx][ny] = true;
            }
        }
    }
}
void solve()
{
    string st, en;
    cin >> st >> en;
    pair<int, int> start = {st[0] - 'a', st[1] - '1'};
    pair<int, int> end = {en[0] - 'a', en[1] - '1'};
    cout << minMoves(start, end) << endl;
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