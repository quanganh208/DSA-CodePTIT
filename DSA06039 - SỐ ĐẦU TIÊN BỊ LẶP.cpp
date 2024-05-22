#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &x : a)
    {
        cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < n; i++)
        if (mp[a[i]] > 1)
        {
            cout << a[i] << endl;
            return;
        }
    cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}