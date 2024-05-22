#include <bits/stdc++.h>
using namespace std;
int n, a[100], vis[100];
string s;
void Try(int m)
{
    if (m > n)
    {
        for (int i = 1; i <= n; i++)
            cout << s[a[i] - 1];
        cout << " ";
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
    cin >> s;
    n = s.length();
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