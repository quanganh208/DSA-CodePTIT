#include <bits/stdc++.h>
using namespace std;
void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            DFS(v, adj, visited);
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
    vector<bool> visited(n + 1, false);
    DFS(1, adj, visited);
    for (int i = 2; i <= n; i++)
        if (!visited[i])
        {
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
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