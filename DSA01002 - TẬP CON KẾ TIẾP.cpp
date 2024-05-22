#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    int i = k;
    while (i > 0 and a[i] == n - k + i)
        i--;
    a[i]++;
    if (i > 0)
        for (int j = i + 1; j <= k; j++)
            a[j] = a[i] + j - i;
    else
        for (int j = 1; j <= k; j++)
            a[j] = j;
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
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