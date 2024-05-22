#include <bits/stdc++.h>
using namespace std;
int maxTriangleSequence(vector<int> nums, int n)
{
    if (n == 0)
        return 0;
    vector<int> increasingDP(n, 1);
    vector<int> decreasingDP(n, 1);
    for (int i = 1; i < n; i++)
        if (nums[i] > nums[i - 1])
            increasingDP[i] = increasingDP[i - 1] + 1;
    for (int i = n - 2; i >= 0; i--)
        if (nums[i] > nums[i + 1])
            decreasingDP[i] = decreasingDP[i + 1] + 1;
    int maxLen = 1;
    for (int i = 0; i < n; i++)
        maxLen = max(maxLen, increasingDP[i] + decreasingDP[i] - 1);
    return maxLen;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    cout << maxTriangleSequence(a, n) << endl;
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