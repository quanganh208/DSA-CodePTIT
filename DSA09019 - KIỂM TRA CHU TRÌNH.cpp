#include <bits/stdc++.h>
using namespace std;
bool hasCycle(vector<vector<int>> &adj, int node, int parent, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : adj[node])
        if (!visited[neighbor])
        {
            if (hasCycle(adj, neighbor, node, visited))
                return true;
        }
        else if (neighbor != parent)
            return true;
    return false;
}
bool hasCycle(vector<vector<int>> adj)
{
    vector<bool> visited(adj.size(), false);
    for (int i = 1; i < adj.size(); i++)
        if (!visited[i] and hasCycle(adj, i, -1, visited))
            return true;
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << (hasCycle(adj) ? "YES" : "NO") << endl;
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