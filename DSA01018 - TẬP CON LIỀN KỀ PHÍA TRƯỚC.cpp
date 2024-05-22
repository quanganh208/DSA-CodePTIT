#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k + 1, 0);
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    int i = k;
    while (i >= 1 and a[i] == a[i - 1] + 1)
        i--;
    if (i != 0)
        a[i]--;
    for (int j = i + 1; j <= k; j++)
        a[j] = n - k + j;
    for (int j = 1; j <= k; j++)
        cout << a[j] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}