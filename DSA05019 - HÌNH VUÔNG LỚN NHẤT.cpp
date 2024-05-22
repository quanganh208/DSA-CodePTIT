#include <bits/stdc++.h>
using namespace std;
int largestSquare(vector<vector<int>> matrix, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSquareSize = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = matrix[i][j];
            else if (matrix[i][j] == 1)
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            maxSquareSize = max(maxSquareSize, dp[i][j]);
        }
    return maxSquareSize;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << largestSquare(a, n, m) << endl;
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