#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int tsp(int n, vector<vector<int>> C)
{
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) == 0)
                continue;
            for (int j = 0; j < n; j++)
            {
                if ((mask & (1 << j)) == 0)
                    continue;
                dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + C[j][i]);
            }
        }
    int minCost = INF;
    for (int i = 1; i < n; i++)
        minCost = min(minCost, dp[(1 << n) - 1][i] + C[i][0]);
    return minCost;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> C[i][j];
    int minCost = tsp(n, C);
    cout << minCost;
    return 0;
}