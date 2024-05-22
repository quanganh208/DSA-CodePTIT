#include <bits/stdc++.h>
using namespace std;
int minInsertions(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++)
        for (int i = 0, j = len - 1; j < n; i++, j++)
            if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
    return dp[0][n - 1];
}
void solve()
{
    string str;
    cin >> str;
    cout << minInsertions(str) << endl;
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