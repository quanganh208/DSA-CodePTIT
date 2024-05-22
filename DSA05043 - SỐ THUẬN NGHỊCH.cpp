#include <bits/stdc++.h>
using namespace std;
int maxPalindromeLength(string str)
{
    int n = str.length();
    int ans = 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++)
        dp[i + 1][i] = 1;
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 0;
            if (dp[i][j])
                ans = len;
        }
    return ans;
}
void solve()
{
    string s;
    cin >> s;
    cout << maxPalindromeLength(s) << endl;
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