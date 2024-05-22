#include <bits/stdc++.h>
using namespace std;
const int maxN = 1005;
int n, m;
vector<int> adj[maxN];
bool visited[maxN];
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
bool isArticulationPoint(int u, int connectedComponent)
{
    memset(visited, 0, sizeof(visited));
    visited[u] = true;
    int cnt = countConnectedComponent(-1, -1);
    return cnt > connectedComponent;
}
void solve()
{
    cin >> n >> m;
    // Init
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    memset(visited, 0, sizeof(visited));
    // Input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Count connected component
    int cnt = countConnectedComponent(-1, -1);
    // Print articulation points
    for (int i = 1; i <= n; i++)
        if (isArticulationPoint(i, cnt))
            cout << i << " ";
    cout << endl;
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