#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << 1 << endl;
        return;
    }
    else
    {
        long long ans = 1;
        for (int i = n - k + 1; i <= n; i++)
            ans = (ans * i) % MOD;
        cout << ans << endl;
    }
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