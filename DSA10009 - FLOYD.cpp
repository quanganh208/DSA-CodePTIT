#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, int>>> adj;
void floyd(vector<vector<int>> &dist)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
        for (auto [u, w] : adj[i])
            dist[i][u] = w;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    floyd(dist);
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}