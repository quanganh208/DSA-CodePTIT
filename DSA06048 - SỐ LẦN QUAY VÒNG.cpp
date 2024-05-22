#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int min = INT_MAX;
    for (auto &x : a)
    {
        cin >> x;
        min = (min > x) ? x : min;
    }
    for (int i = 0; i < n; i++)
        if (a[i] == min)
            cout << i << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}