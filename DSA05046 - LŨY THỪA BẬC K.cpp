#include <bits/stdc++.h>
using namespace std;
#define MAX 2510
#define MOD 1000000007
int S[MAX][MAX], inv[MAX];
int expo(long long x, int n)
{
    x %= MOD;
    long long res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return (res % MOD);
}
void generate()
{
    for (int i = 0; i < MAX; i++)
        inv[i] = expo(i, MOD - 2);
    S[0][0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        S[i][0] = 0;
        for (int j = 1; j <= i; j++)
            S[i][j] = (((long long)S[i - 1][j] * j) + S[i - 1][j - 1]) % MOD;
    }
}
int faulhaber(long long n, int k)
{
    n %= MOD;
    if (!k)
        return n;
    long long res = 0, p = 1;
    for (int j = 0; j <= k; j++)
    {
        p = (p * (n + 1 - j)) % MOD;
        res = (res + (((S[k][j] * p) % MOD) * inv[j + 1])) % MOD;
    }
    return (res % MOD);
}
void solve()
{
    long long n;
    int k;
    cin >> n >> k;
    cout << faulhaber(n, k) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    generate();
    while (t--)
        solve();
    return 0;
}