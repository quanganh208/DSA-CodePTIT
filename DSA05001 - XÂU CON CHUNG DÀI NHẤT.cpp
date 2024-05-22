#include <bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2)
{
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    for (int i = 0; i < s1.size(); i++)
        for (int j = 0; j < s2.size(); j++)
            if (s1[i] == s2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    return dp[s1.size()][s2.size()];
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}