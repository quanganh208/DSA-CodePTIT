#include <iostream>
#include <vector>
using namespace std;
void trace(vector<vector<int>> &dp, const vector<int> w, string &ans, int n, int k)
{
    if (n == 0)
        return;
    if (dp[n][k] == dp[n - 1][k])
        trace(dp, w, ans, n - 1, k);
    else
    {
        trace(dp, w, ans, n - 1, k - w[n]);
        ans[n - 1] = '1';
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> w(n + 1);
    vector<int> v(n + 1);
    string ans(n, '0');
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
    cout << dp[n][m] << endl;
    trace(dp, w, ans, n, m);
    for (auto x : ans)
        cout << x << " ";
}
int main()
{
    solve();
    return 0;
}