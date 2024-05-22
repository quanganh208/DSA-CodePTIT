#include <bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i][j - 1],       // Insert
                                    dp[i - 1][j],       // Delete
                                    dp[i - 1][j - 1]}); // Replace
    return dp[m][n];
}
void solve()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << minDistance(str1, str2) << endl;
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