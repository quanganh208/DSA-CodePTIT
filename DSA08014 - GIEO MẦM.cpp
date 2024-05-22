#include <bits/stdc++.h>
using namespace std;
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void solve()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> grid(R, vector<int>(C));
    queue<tuple<int, int, int>> q; // (row, col, days)
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
                q.emplace(i, j, 0);
        }
    vector<vector<int>> days(R, vector<int>(C, -1));
    while (!q.empty())
    {
        auto [r, c, d] = q.front();
        q.pop();
        for (const auto &dir : directions)
        {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1 && days[nr][nc] == -1)
            {
                days[nr][nc] = d + 1;
                q.emplace(nr, nc, d + 1);
            }
        }
    }
    int max_days = 0;
    bool possible = true;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == 1)
            {
                if (days[i][j] == -1)
                    possible = false;
                else
                    max_days = max(max_days, days[i][j]);
            }
    cout << (possible ? max_days : -1) << endl;
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