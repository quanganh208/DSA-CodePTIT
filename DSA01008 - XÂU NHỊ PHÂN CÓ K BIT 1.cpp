#include <bits/stdc++.h>
using namespace std;
void Try(int n, int k, string ans, int count)
{
    if (count == k)
    {
        for (int i = 1; i <= n; i++)
            ans += "0";
        cout << ans << endl;
        return;
    }
    if (n > 0)
    {
        Try(n - 1, k, ans + "0", count);
        Try(n - 1, k, ans + "1", count + 1);
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    Try(n, k, "", 0);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}