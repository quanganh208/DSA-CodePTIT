#include <bits/stdc++.h>
using namespace std;
int minTime(int N, int X, int Y, int Z)
{
    vector<int> dp(N + 1);
    dp[1] = X;
    for (int i = 2; i <= N; i++)
    {
        if (i % 2)
            dp[i] = min({dp[i - 1] + X, dp[(i - 1) / 2] + Z + X, dp[(i + 1) / 2] + Z + Y});
        else
            dp[i] = min(dp[i - 1] + X, dp[i / 2] + Z);
    }
    return dp[N];
}
void solve()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << minTime(n, x, y, z) << endl;
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