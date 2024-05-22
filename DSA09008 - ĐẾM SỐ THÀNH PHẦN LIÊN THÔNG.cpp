#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    fill(visited, visited + maxN, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << countConnectedComponent(-1, -1) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}