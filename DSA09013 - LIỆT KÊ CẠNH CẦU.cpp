#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
int n, m;
vector<int> adj[maxN];
bool visited[maxN];
vector<pair<int, int>> edges;
void dfs(int u, int x, int y)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if ((u == x and v == y) or (u == y and v == x))
            continue;
        if (!visited[v])
            dfs(v, x, y);
    }
}
int countConnectedComponent(int x, int y)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!visited[i])
        {
            dfs(i, x, y);
            cnt++;
        }
    return cnt;
}
void findBridge()
{
    int connectedComponent = countConnectedComponent(-1, -1);
    for (pair<int, int> edge : edges)
    {
        int u = edge.first, v = edge.second;
        fill(visited, visited + maxN, false);
        int cnt = countConnectedComponent(u, v);
        if (cnt > connectedComponent)
            cout << u << " " << v << " ";
    }
    cout << endl;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    edges.clear();
    fill(visited, visited + maxN, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    findBridge();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}