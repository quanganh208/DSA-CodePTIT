#include <bits/stdc++.h>
using namespace std;
long long countWays(int n, int m, unordered_map<int, unordered_map<int, long long>> &memo)
{
    if (memo[n][m] != 0)
        return memo[n][m];
    if (n == 0 || m == 0)
        return 1;
    long long ways = countWays(n - 1, m, memo) + countWays(n, m - 1, memo);
    memo[n][m] = ways;
    return ways;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_map<int, long long>> memo;
    long long ways = countWays(n, m, memo);
    cout << ways << endl;
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