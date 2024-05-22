#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>> adj, int v, int u)
{
    vector<int> visited(v + 1, 0);
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        cout << s << " ";
        for (int i = 1; i <= v; i++)
            if (adj[s][i] and !visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
    }
    cout << endl;
}
void solve()
{
    int v, e, u;
    cin >> v >> e >> u;
    vector<vector<int>> adj(v + 1, vector<int>(v + 1));
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    BFS(adj, v, u);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}