#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX 15
int n, dist[MAX][MAX], dp[MAX][1 << MAX];
int tsp(int i, int mask)
{
    if (mask == (1 << n) - 1)
        return 0;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
        if (i != j and !(mask & (1 << j)))
            ans = min(ans, dist[i][j] + tsp(j, mask | (1 << j)));
    return dp[i][mask] = ans;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    memset(dp, -1, sizeof dp);
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
        res = min(res, tsp(i, 1 << i));
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}