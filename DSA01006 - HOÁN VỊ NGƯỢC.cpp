#include <bits/stdc++.h>
using namespace std;
int n, a[100], vis[100];
void Try(int m)
{
    if (m > n)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << " ";
        return;
    }
    for (int i = n; i >= 1; i--)
        if (!vis[i])
        {
            a[m] = i;
            vis[i] = 1;
            Try(m + 1);
            vis[i] = 0;
        }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
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