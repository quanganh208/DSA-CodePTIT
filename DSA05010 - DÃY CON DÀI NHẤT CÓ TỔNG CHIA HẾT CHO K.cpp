#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> f(n + 1, vector<int>(k, -1));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            if (f[i - 1][j] != -1)
            {
                f[i][(j + a[i]) % k] = max(f[i][(j + a[i]) % k], f[i - 1][j] + 1);
                f[i][j] = max(f[i][j], f[i - 1][j]);
            }
    cout << f[n][0] << endl;
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