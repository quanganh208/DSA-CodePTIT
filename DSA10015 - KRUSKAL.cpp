#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int src, dest, weight;
};
int n, m;
bool visited[1001];
vector<int> adj[1001];
void dfs(int u, vector<int> adj[])
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(v, adj);
    }
}
void solve()
{
    for (int i = 0; i < 1001; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(edges.begin(), edges.end(), [](Edge const a, Edge const b)
         { return a.weight < b.weight; });
    int ans = 0;
    for (auto e : edges)
    {
        memset(visited, false, sizeof(visited));
        dfs(e.src, adj);
        if (!visited[e.dest])
        {
            adj[e.src].push_back(e.dest);
            adj[e.dest].push_back(e.src);
            ans += e.weight;
        }
    }
    cout << ans << endl;
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