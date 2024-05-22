#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int V;                   // Số đỉnh
    vector<vector<int>> adj; // Danh sách kề
    bool isCyclicUtil(int v, vector<bool> &visited, vector<bool> &recStack)
    {
        if (!visited[v])
        {
            visited[v] = true;
            recStack[v] = true;
            for (int i = 0; i < adj[v].size(); ++i)
            {
                int neighbor = adj[v][i];
                if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack))
                    return true;
                else if (recStack[neighbor])
                    return true;
            }
        }
        recStack[v] = false; // Xóa đỉnh khỏi stack sau khi duyệt xong
        return false;
    }
public:
    Graph(int V) : V(V)
    {
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    bool isCyclic()
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        for (int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recStack))
                return true;
        return false;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u - 1, v - 1);
    }
    cout << (g.isCyclic() ? "YES" : "NO") << endl;
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