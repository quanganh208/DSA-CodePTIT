#include <bits/stdc++.h>
using namespace std;
long long dynamicProgramming(const string s)
{
    vector<long long> dp(s.size(), s[0] - '0');
    long long ans = dp[0];
    for (int i = 1; i < s.size(); i++)
    {
        dp[i] = dp[i - 1] * 10 + (s[i] - '0') * (i + 1);
        ans += dp[i];
    }
    return ans;
}
void solve()
{
    string s;
    cin >> s;
    cout << dynamicProgramming(s) << endl;
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