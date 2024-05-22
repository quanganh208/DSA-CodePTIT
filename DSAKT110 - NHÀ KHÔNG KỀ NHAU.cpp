#include <iostream>
#include <vector>
using namespace std;
int dynamicProgramming(vector<int> a, int n)
{
    if (n == 1)
        return a[0];
    if (n == 2)
        return max(a[0], a[1]);
    vector<int> dp(n);
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    return dp[n - 1];
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << dynamicProgramming(a, n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}