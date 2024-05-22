#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, bool> mp;
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        if (p.first == 2)
        {
            cout << p.second + 1 << endl;
            return;
        }
        for (int i = 2; i <= sqrt(p.first); ++i)
        {
            if (p.first % i == 0 and !mp[p.first / i])
            {
                mp[p.first / i] = true;
                q.push({p.first / i, p.second + 1});
            }
        }
        q.push({p.first - 1, p.second + 1});
    }
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