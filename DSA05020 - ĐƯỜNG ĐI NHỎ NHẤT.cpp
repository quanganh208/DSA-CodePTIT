#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int minSumPath(vector<vector<int>> A, int N, int M)
{
    vector<vector<int>> dp(N, vector<int>(M, INF));
    dp[0][0] = A[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (i > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[i][j]);
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + A[i][j]);
            if (i > 0 and j > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + A[i][j]);
        }
    return dp[N - 1][M - 1];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << minSumPath(a, n, m) << endl;
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