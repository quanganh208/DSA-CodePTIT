#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> ans;
vector<bool> visited;
void DFS(int u, int parent, vector<int> path)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == 1 && v != parent && ans.empty())
        {
            path.push_back(v);
            ans = path;
            return;
        }
        if (!visited[v])
        {
            path.push_back(v);
            DFS(v, u, path);
            path.pop_back();
        }
    }
}
void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    ans.clear();
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (auto &i : adj)
        sort(i.begin(), i.end());
    DFS(1, -1, {1});
    if (ans.empty())
        cout << "NO";
    else
        for (int i : ans)
            cout << i << " ";
    cout << endl;
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