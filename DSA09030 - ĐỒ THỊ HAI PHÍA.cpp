#include <bits/stdc++.h>
using namespace std;
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int neighbor : graph[curr])
                    if (color[neighbor] == -1)
                    {
                        color[neighbor] = 1 - color[curr];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[curr])
                        return false;
            }
        }
    return true;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << (isBipartite(graph) ? "YES" : "NO") << endl;
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