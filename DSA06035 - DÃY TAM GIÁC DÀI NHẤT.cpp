#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> inc(n, 0), dec(n, 0);
    for (int i = 0; i < n - 1; i++)
        if (a[i] < a[i + 1])
            inc[i + 1] = inc[i] + 1;
    for (int i = n - 1; i >= 1; i--)
        if (a[i] < a[i - 1])
            dec[i - 1] = dec[i] + 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, inc[i] + dec[i] + 1);
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