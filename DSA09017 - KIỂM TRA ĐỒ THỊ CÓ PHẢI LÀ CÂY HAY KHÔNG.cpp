#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            DFS(v);
}
void solve()
{
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int i = 1; i <= n; i++)
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