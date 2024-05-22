#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<vector<int>> tmp;
vector<vector<int>> multiple(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
    return c;
}
void pow(vector<vector<int>> &a, int n)
{
    if (n == 1)
        return;
    pow(a, n / 2);
    a = multiple(a, a);
    if (n & 1)
        a = multiple(a, tmp);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    tmp = a;
    pow(a, k);
    for (auto x : a)
    {
        for (int y : x)
            cout << y << " ";
        cout << endl;
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