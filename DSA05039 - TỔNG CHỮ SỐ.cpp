#include <bits/stdc++.h>
using namespace std;
bool compare(string s1, string s2)
{
    if (s1.length() != s2.length())
        return s1.length() < s2.length();
    return s1 < s2;
}
string makeString(string s, int k)
{
    string res;
    if (s == "0")
        res = to_string(k);
    else
        res = s + to_string(k);
    sort(res.begin(), res.end());
    return res;
}
string findN(int A, int B)
{
    string INF(100, '9');
    vector<vector<string>> dp(A + 1, vector<string>(B + 1, INF));
    dp[0][0] = "0";
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            for (int k = 1; k * k <= min(i * i, min(j, 81)); k++)
                if (dp[i - k][j - k * k] != INF)
                {
                    string s = makeString(dp[i - k][j - k * k], k);
                    if (compare(s, dp[i][j]))
                        dp[i][j] = s;
                }
    return (dp[A][B] == INF) ? "-1" : dp[A][B];
}
void solve()
{
    int A, B;
    cin >> A >> B;
    cout << findN(A, B) << endl;
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