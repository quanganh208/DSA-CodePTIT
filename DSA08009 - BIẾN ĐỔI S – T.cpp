#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int s, t;
    cin >> s >> t;
    queue<pair<int, int>> q;
    map<int, bool> mp;
    q.push({s, 0});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        if (p.first == t)
        {
            cout << p.second << endl;
            return;
        }
        if (p.first - 1 == t or p.first * 2 == t)
        {
            cout << p.second + 1 << endl;
            return;
        }
        if (p.first * 2 <= t * 2 and mp[p.first * 2] == 0)
        {
            q.push({p.first * 2, p.second + 1});
            mp[p.first * 2] = 1;
        }
        if (p.first - 1 >= 0 and mp[p.first - 1] == 0)
        {
            q.push({p.first - 1, p.second + 1});
            mp[p.first - 1] = 1;
        }
    }
    cout << "HEHEHEHEEEEEHHEHEHEEHEEHE" << endl;
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