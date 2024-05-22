#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int n, m, cnt;
void Try(int i, int j)
{
    if (i < 0 or i >= n or j < 0 or j >= m)
        return;
    if (i == n - 1 and j == m - 1)
    {
        cnt++;
        return;
    }
    Try(i + 1, j);
    Try(i, j + 1);
}
void solve()
{
    cin >> n >> m;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        a[i].resize(m);
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    cnt = 0;
    Try(0, 0);
    cout << cnt << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}