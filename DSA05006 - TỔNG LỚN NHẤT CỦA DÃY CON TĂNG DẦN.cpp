#include <bits/stdc++.h>
using namespace std;
int dynamicProgramming(int n, vector<int> a)
{
    vector<int> dp(n, 0);
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = a[i];
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    return *max_element(dp.begin(), dp.end());
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << dynamicProgramming(n, a) << endl;
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