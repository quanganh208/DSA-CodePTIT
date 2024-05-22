#include <bits/stdc++.h>
using namespace std;
class Data
{
public:
    int row, col, count;
    Data(int row, int col, int count)
    {
        this->row = row;
        this->col = col;
        this->count = count;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<bool>> vs(n + 1, vector<bool>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    queue<Data> q;
    q.push(Data(1, 1, 0));
    while (!q.empty())
    {
        Data u = q.front();
        q.pop();
        int i = u.row, j = u.col;
        if (i == n and j == m)
        {
            cout << u.count << endl;
            return;
        }
        if (i + a[i][j] <= n and !vs[i + a[i][j]][j])
        {
            vs[i + a[i][j]][j] = 1;
            q.push(Data(i + a[i][j], j, u.count + 1));
        }
        if (j + a[i][j] <= m and !vs[i][j + a[i][j]])
        {
            vs[i][j + a[i][j]] = 1;
            q.push(Data(i, j + a[i][j], u.count + 1));
        }
    }
    cout << -1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}