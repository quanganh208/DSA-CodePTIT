#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int v, e, m;
    cin >> v >> e >> m;
    vector<vector<int>> adj(v + 1, vector<int>(v + 1, 0));
    map<int, int> deg;
    vector<pair<int, int>> degIdx;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= v; i++)
        degIdx.push_back({i, deg[i]});
    sort(degIdx.begin(), degIdx.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second > b.second; });
    vector<int> color(v + 1, 0);
    int cnt = 0;
    for (auto x : degIdx)
    {
        auto a = x.first;
        if (!color[a])
        {
            cnt++;
            color[a] = cnt;
            for (int i = 1; i <= v; i++)
                if (!color[i] and !adj[a][i])
                    color[i] = cnt;
        }
    }
    cout << ((cnt <= m) ? "YES" : "NO") << endl;
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