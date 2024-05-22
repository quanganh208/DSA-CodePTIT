#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
int dp[MAX][1 << MAX], a[MAX][MAX], n;
int DynamicProgramming(int i, int mask)
{
    if (i == n)
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        if ((mask >> j) & 1)
            continue;
        ans = max(ans, a[i][j] + DynamicProgramming(i + 1, mask | (1 << j)));
    }
    return dp[i][mask] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    memset(dp, -1, sizeof(dp));
    cout << DynamicProgramming(0, 0) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}