#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int countIncreasingNumbers(int N)
{
    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));
    for (int i = 0; i <= 9; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= j; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
    long long count = 0;
    for (int i = 0; i <= 9; i++)
        count = (count + dp[N][i]) % mod;
    return count;
}
void solve()
{
    int n;
    cin >> n;
    cout << countIncreasingNumbers(n) << endl;
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