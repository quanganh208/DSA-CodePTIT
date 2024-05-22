#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> a, int x)
{
    int l = 0, r = a.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int idx = binarySearch(a, k);
    if (idx == -1)
        cout << "NO" << endl;
    else
        cout << idx + 1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}