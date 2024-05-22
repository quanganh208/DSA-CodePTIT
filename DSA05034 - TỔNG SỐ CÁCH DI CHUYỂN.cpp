#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int dynamicProgramming(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= min(i, k); j++)
            dp[i] = (dp[i] + dp[i - j]) % MOD;
    return dp[n];
}
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << dynamicProgramming(n, k) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}