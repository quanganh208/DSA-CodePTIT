#include <bits/stdc++.h>
using namespace std;
int dynamicProgramming(vector<int> a)
{
    vector<int> dp(a.size(), 1);
    for (int i = 1; i < a.size(); i++)
        for (int j = 0; j < i; j++)
            if (a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
    return a.size() - *max_element(dp.begin(), dp.end());
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << dynamicProgramming(a) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}