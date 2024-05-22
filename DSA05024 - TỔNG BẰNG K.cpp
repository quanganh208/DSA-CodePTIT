#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long dynamicProgramming(vector<int> a, int n, int k)
{
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j < n; j++)
            if (i >= a[j])
                dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
    return dp[k];
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << dynamicProgramming(a, n, k) << endl;
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