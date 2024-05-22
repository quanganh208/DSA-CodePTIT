#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(m + n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    cout << a[k - 1] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}