#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int c, n, w;
    cin >> c >> n;
    vector<bool> dp(c + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        for (int j = c; j >= w; j--)
            if (!dp[j] and dp[j - w])
                dp[j] = 1;
    }
    for (int i = c; i >= 0; i--)
        if (dp[i])
        {
            cout << i;
            return;
        }
}
int main()
{
    solve();
    return 0;
}