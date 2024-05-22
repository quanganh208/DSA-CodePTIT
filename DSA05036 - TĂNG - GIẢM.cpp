#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<float, float>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    int ans = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (a[i].first > a[j].first and a[i].second < a[j].second and dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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