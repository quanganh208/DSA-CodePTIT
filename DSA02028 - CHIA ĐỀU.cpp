#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
int res = 0;
void Try(int x, int l, int r, int k)
{
    if (l > r)
        return;
    if (k == 1)
    {
        if (a[r] - a[l - 1] == x)
            res += 1;
        return;
    }
    for (int i = l; i <= r; i++)
        if (a[i] - a[l - 1] == x)
            Try(x, i + 1, r, k - 1);
}
void solve()
{
    cin >> n >> k;
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    if (k == 1)
        res = 1;
    else
        for (int i = 1; i <= n; i++)
            Try(a[i], i + 1, n, k - 1);
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}