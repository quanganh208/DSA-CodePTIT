#include <bits/stdc++.h>
using namespace std;
void BFS(int u, vector<bool> &visited, vector<int> adj[], vector<pair<int, int>> &parent)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i : adj[x])
            if (!visited[i])
            {
                visited[i] = true;
                parent.push_back({x, i});
                q.push(i);
            }
    }
}
void constructMST(int v, int u, vector<int> adj[])
{
    vector<bool> visited(v + 1, false);
    vector<pair<int, int>> parent;
    BFS(u, visited, adj, parent);
    if (parent.size() != v - 1)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= v; i++)
        if (!visited[i])
        {
            cout << -1 << endl;
            return;
        }
    for (auto i : parent)
        cout << i.first << " " << i.second << endl;
}
void solve()
{
    int v, e, u;
    cin >> v >> e >> u;
    vector<int> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    constructMST(v, u, adj);
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