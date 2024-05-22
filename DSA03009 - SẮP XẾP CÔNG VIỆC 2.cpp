#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, trash, maxDL = INT_MIN;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> trash >> a[i].first >> a[i].second;
        maxDL = max(maxDL, a[i].first);
    }
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y)
         { if (x.second == y.second) return x.first > y.first;
           return x.second > y.second; });
    vector<int> vis(maxDL + 1, 0);
    pair<int, int> res = {0, 0};
    for (int i = 0; i < n; i++)
        for (int j = a[i].first; j > 0; j--)
            if (!vis[j])
            {
                vis[j] = 1;
                res.first++;
                res.second += a[i].second;
                break;
            }
    cout << res.first << " " << res.second << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}