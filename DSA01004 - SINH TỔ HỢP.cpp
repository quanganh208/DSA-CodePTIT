#include <bits/stdc++.h>
using namespace std;
int n, k, a[100];
void Try(int m)
{
    if (m > k)
    {
        for (int i = 1; i <= k; i++)
            cout << a[i];
        cout << " ";
        return;
    }
    for (int i = a[m - 1] + 1; i <= n - k + m; i++)
    {
        a[m] = i;
        Try(m + 1);
    }
}
void solve()
{
    cin >> n >> k;
    Try(1);
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}