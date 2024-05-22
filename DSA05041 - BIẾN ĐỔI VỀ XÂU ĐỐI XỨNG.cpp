#include <bits/stdc++.h>
using namespace std;
int minRemovalsToPalindrome(const string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++)
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
        }
    return dp[0][n - 1];
}
void solve()
{
    string s;
    cin >> s;
    cout << minRemovalsToPalindrome(s) << endl;
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