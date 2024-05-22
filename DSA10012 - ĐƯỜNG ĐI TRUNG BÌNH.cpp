#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
int BFS(int u, int v)
{
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    q.push({u, 0});
    visited[u] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (node == v)
            return dist;
        for (auto &i : adj[node])
            if (!visited[i])
            {
                if (i == v)
                    return dist + 1;
                visited[i] = true;
                q.push({i, dist + 1});
            }
    }
    return 0;
}
void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
            {
                int dist = BFS(i, j);
                if (dist)
                {
                    sum += dist;
                    cnt++;
                }
            }
    cout << fixed << setprecision(2) << (double)sum / cnt << endl;
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