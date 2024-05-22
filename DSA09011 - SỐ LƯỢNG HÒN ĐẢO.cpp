#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y, vector<vector<int>> &a)
{
    a[x][y] = 0;
    for (int i = 0; i < 8; i++)
    {
        int u = x + dx[i];
        int v = y + dy[i];
        if (u >= 0 and u < a.size() and v >= 0 and v < a[0].size() and a[u][v] == 1)
            dfs(u, v, a);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j])
            {
                count++;
                dfs(i, j, a);
            }
    cout << count << endl;
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