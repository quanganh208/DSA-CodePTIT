#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> a;
void dijkstra(int s)
{
    vector<int> dist(n * m + 1, INT_MAX);
    dist[s] = a[0][0];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({a[0][0], s});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d != dist[u])
            continue;
        for (pair<int, int> edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[n * m] << endl;
}
void solve()
{
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    adj.assign(n * m + 1, vector<pair<int, int>>());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int u = i * m + j + 1;
            if (i > 0)
                adj[u].push_back({(i - 1) * m + j + 1, a[i - 1][j]});
            if (i < n - 1)
                adj[u].push_back({(i + 1) * m + j + 1, a[i + 1][j]});
            if (j > 0)
                adj[u].push_back({i * m + j, a[i][j - 1]});
            if (j < m - 1)
                adj[u].push_back({i * m + j + 2, a[i][j + 1]});
        }
    dijkstra(1);
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