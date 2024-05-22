#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<vector<int>> graph;
bool hamitonian(int u, vector<bool> &visited, int count)
{
    if (count == v)
        return true;
    visited[u] = true;
    for (int v : graph[u])
        if (!visited[v] and hamitonian(v, visited, count + 1))
            return true;
    visited[u] = false;
    return false;
}
void solve()
{
    cin >> v >> e;
    graph.assign(v + 100, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool flag = false;
    for (int i = 1; i <= v; i++)
    {
        vector<bool> visited(v + 100, false);
        if (hamitonian(i, visited, 1))
        {
            flag = true;
            break;
        }
    }
    cout << flag << endl;
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