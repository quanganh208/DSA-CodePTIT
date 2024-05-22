#include <bits/stdc++.h>
using namespace std;
int n, k, a[100], b[100], cnt;
bool check(int a[100], int b[100], int k)
{
    for (int i = 1; i <= k; i++)
        if (a[i] != b[i])
            return false;
    return true;
}
void Try(int m)
{
    if (m > k)
    {
        cnt++;
        if (check(a, b, k))
            cout << cnt << endl;
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
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    cnt = 0;
    Try(1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}