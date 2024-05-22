#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
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
    long long a, b;
    do
    {
        cin >> a >> b;
        if (a or b)
            cout << power(a, b) << endl;
    } while (a or b);
}
int main()
{
    solve();
    return 0;
}