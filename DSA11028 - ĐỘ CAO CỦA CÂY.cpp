#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int height[100001];
void dfs(int node, int parent, int h)
{
    height[node] = h;
    for (int child : adj[node])
        if (child != parent)
            dfs(child, node, h + 1);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, 0);
    cout << *max_element(height + 1, height + n + 1) << endl;
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