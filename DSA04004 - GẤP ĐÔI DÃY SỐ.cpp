#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n, 1);
    for (int i = 1; i < n; i++)
        a[i] = a[i - 1] * 2;
    for (int i = n - 1; i >= 0; i--)
        if (k == a[i])
        {
            cout << i + 1 << endl;
            return;
        }
        else if (k > a[i])
            k -= a[i];
    // Cách 2: cout<<__builtin_ctzll(k)+1<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}