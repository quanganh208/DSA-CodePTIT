#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<vector<int>> adj, vector<bool> &visited, int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
    }
}
void solve()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v + 1, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        vector<bool> visited(v + 1, false);
        BFS(adj, visited, s);
        cout << (visited[t] ? "YES" : "NO") << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}