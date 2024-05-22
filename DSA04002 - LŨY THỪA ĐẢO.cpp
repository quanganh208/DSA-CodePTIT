#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(long long a, long long k)
{
    if (k == 0)
        return 1;
    long long tmp = power(a, k / 2);
    return (k & 1) ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}
long long reverse(long long a)
{
    long long ans = 0;
    while (a)
    {
        ans = ans * 10 + a % 10;
        a /= 10;
    }
    return ans;
}
void solve()
{
    long long n;
    cin >> n;
    cout << power(n, reverse(n)) << endl;
}
main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}