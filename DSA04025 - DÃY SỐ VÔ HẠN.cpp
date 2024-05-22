#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<vector<long long>> multiply(const vector<vector<long long>> a, const vector<vector<long long>> b)
{
    int n = a.size();
    vector<vector<long long>> c(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    return c;
}
vector<vector<long long>> power(const vector<vector<long long>> a, long long b)
{
    if (b == 1)
        return a;
    vector<vector<long long>> t = power(a, b / 2);
    t = multiply(t, t);
    if (b % 2 == 1)
        t = multiply(t, a);
    return t;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<long long>> a({{1, 1}, {1, 0}});
    vector<vector<long long>> b = power(a, n - 1);
    cout << b[0][0] % MOD << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}