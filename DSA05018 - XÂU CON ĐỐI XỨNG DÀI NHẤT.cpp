#include <bits/stdc++.h>
using namespace std;
int longestPalindromeSubstring(const string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0;
    int max_len = 1;
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            max_len = 2;
        }
    for (int len = 3; len <= n; len++)
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] and dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                start = i;
                max_len = len;
            }
        }
    return max_len;
}
void solve()
{
    string s;
    cin >> s;
    cout << longestPalindromeSubstring(s) << endl;
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