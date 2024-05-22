#include <bits/stdc++.h>
using namespace std;
int longest_common_subsequence(string X, string Y, string Z, int m, int n, int p)
{
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(p + 1, 0)));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= p; k++)
                if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
    return dp[m][n][p];
}
void solve()
{
    int m, n, p;
    cin >> m >> n >> p;
    string x, y, z;
    cin >> x >> y >> z;
    cout << longest_common_subsequence(x, y, z, m, n, p) << endl;
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