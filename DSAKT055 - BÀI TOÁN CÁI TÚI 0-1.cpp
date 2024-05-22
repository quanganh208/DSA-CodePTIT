#include <bits/stdc++.h>
using namespace std;
int dynamicProgramming(vector<int> a, vector<int> c, int v)
{
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= v; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1] <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] + c[i - 1]);
        }
    return dp[n][v];
}
void solve()
{
    int n, v;
    cin >> n >> v;
    vector<int> a(n), c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    cout << dynamicProgramming(a, c, v) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}