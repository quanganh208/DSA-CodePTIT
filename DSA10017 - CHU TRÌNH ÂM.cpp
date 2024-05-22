#include <bits/stdc++.h>
using namespace std;
bool BFS(vector<vector<pair<int, int>>> &graph, vector<bool> &visited, int n)
{
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int weight = q.front().second;
        q.pop();
        for (auto i : graph[node])
        {
            if (i.first == n and i.second + weight < 0)
                return true;
            if (!visited[i.first])
            {
                visited[i.first] = true;
                q.push({i.first, i.second + weight});
            }
        }
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
    {
        vector<bool> visited(n + 1, false);
        if (BFS(graph, visited, i))
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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