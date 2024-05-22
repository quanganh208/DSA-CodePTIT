#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void BFS(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &mark, int s, int t)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    mark[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (!visited[v])
            {
                visited[v] = true;
                mark[v] = u;
                q.push(v);
            }
    }
}
void solve()
{
    int v, e, s, t;
    cin >> v >> e >> s >> t;
    vector<vector<int>> adj(v + 1, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(v + 1, false);
    vector<int> mark(v + 1, -1);
    BFS(adj, visited, mark, s, t);
    if (!visited[t])
    {
        cout << -1 << endl;
        return;
    }
    vector<int> path;
    int prev = t;
    while (prev != -1)
    {
        path.push_back(prev);
        prev = mark[prev];
    }
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}