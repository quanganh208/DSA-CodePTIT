#include <bits/stdc++.h>
using namespace std;
const long long MOD = 123456789;
long long power(long long a, long long b)
{
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}
void solve()
{
    long long n;
    cin >> n;
    cout << power(2, n - 1) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}