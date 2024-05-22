#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<vector<int>> dp(1005, vector<int>(1005, 1));
void dynamicProgramming()
{
    for (int i = 2; i <= 1000; i++)
        for (int j = 0; j <= i; j++)
            if (j and j < i)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << dp[n][k] << endl;
}
int main()
{
    int t;
    cin >> t;
    dynamicProgramming();
    while (t--)
        solve();
    return 0;
}