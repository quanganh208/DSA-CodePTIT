#include <bits/stdc++.h>
using namespace std;
int n, a[100], vis[100], b[100];
void Try(int m)
{
    if (m > n)
    {
        for (int i = 1; i <= n; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
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
        cin >> b[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    Try(1);
    cout << endl;
}
int main()
{
    solve();
    return 0;
}