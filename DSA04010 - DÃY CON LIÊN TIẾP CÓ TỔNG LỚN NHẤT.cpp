#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> nums)
{
    int max_ending_here = 0, max_so_far = INT_MIN;
    for (auto num : nums)
    {
        max_ending_here = max(0, max_ending_here + num);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    cout << maxSubArray(a) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}