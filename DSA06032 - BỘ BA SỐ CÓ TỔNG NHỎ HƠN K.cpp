#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] + a[i + 1] >= k)
            break;
        for (int j = i + 1; j < n - 1; j++)
        {
            int pos = lower_bound(a.begin() + j + 1, a.end(), k - a[i] - a[j]) - a.begin();
            ans += pos - (j + 1);
        }
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