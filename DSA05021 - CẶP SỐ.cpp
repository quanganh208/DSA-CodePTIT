#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++)
        cin >> pairs[i].first >> pairs[i].second;
    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)
         { return p1.first < p2.first; });
    int maxLength = 0;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (pairs[i].first > pairs[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        maxLength = max(maxLength, dp[i]);
    }
    cout << maxLength << endl;
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