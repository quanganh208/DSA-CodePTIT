#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int pos = lower_bound(a.begin() + i + 1, a.end(), k + a[i]) - a.begin();
        ans += pos - i - 1;
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}