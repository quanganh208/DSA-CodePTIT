#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, x, tmp;
    cin >> n >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        mp[tmp]++;
    }
    if (mp[x] == 0)
        cout << "-1" << endl;
    else
        cout << mp[x] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}