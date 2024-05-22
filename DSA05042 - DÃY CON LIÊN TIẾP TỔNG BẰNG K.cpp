#include <bits/stdc++.h>
using namespace std;
bool hasSubarrayWithSum(vector<int> a, int n, long long sum)
{
    unordered_set<long long> s;
    long long prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += a[i];
        if (prefix_sum == sum)
            return true;
        if (s.find(prefix_sum - sum) != s.end())
            return true;
        s.insert(prefix_sum);
    }
    return false;
}
void solve()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << (hasSubarrayWithSum(a, n, k) ? "YES" : "NO") << endl;
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