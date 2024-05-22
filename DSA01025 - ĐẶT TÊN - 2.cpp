#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
void Try(int i)
{
    if (i > k)
    {
        for (int j = 1; j <= k; j++)
            cout << char(a[j] + 'A' - 1);
        cout << endl;
        return;
    }
    for (int j = a[i - 1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        Try(i + 1);
    }
}
void solve()
{
    cin >> n >> k;
    a.resize(k + 1, 0);
    for (int i = 1; i <= k; i++)
        a[i] = i;
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