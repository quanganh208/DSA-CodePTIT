#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, x;
    cin >> n >> m;
    map<int, int> mp;
    set<int> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x] = 1;
        ans.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        if (mp[x])
            mp[x] = 2;
        ans.insert(x);
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    for (auto i : mp)
        if (i.second == 2)
            cout << i.first << " ";
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