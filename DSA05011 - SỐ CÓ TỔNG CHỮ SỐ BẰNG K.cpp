#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int countNumbers(int N, int K)
{
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++)
            for (int digit = 0; digit <= 9; digit++)
                if (j - digit >= 0)
                {
                    dp[i][j] += dp[i - 1][j - digit];
                    dp[i][j] %= mod;
                }
    return dp[N][K];
}
void solve()
{
    int N, K;
    cin >> N >> K;
    cout << countNumbers(N, K) << endl;
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