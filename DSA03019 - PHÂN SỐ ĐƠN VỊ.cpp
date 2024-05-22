#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long p, q;
    cin >> p >> q;
    while (true)
    {
        if (q % p == 0)
        {
            cout << "1/" << q / p << endl;
            return;
        }
        long long x = q / p + 1;
        cout << "1/" << x << " + ";
        p = p * x - q;
        q *= x;
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