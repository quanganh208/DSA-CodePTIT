#include <bits/stdc++.h>
using namespace std;
long long dynamicProgramming(int n)
{
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= 3; j++)
            if (i - j >= 0)
                dp[i] += dp[i - j];
    return dp[n];
}
void solve()
{
    int n;
    cin >> n;
    cout << dynamicProgramming(n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}