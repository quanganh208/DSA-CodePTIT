#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    map<int, int> mp;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mp[i + j] += a[i] * b[j];
    for (auto x : mp)
        cout << x.second << " ";
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