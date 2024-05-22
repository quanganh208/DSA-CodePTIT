#include <bits/stdc++.h>
using namespace std;
int floor(vector<long long> a, int k)
{
    if (a[0] > k)
        return -1;
    int idx = lower_bound(a.begin(), a.end(), k) - a.begin();
    if (a[idx] == k)
        return idx + 1;
    return idx;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    cout << floor(a, k) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}