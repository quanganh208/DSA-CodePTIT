#include <bits/stdc++.h>
using namespace std;
int n, a[100];
void Try(int m)
{
    if (m > n)
    {
        for (int i = 1; i <= n; i++)
            cout << char(a[i] + 'A');
        cout << " ";
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        a[m] = i;
        Try(m + 1);
    }
}
void solve()
{
    cin >> n;
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