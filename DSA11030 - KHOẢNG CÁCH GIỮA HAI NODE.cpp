#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
const int LOG = 10; // log2(1000) is about 10
vector<int> adj[MAXN];
int depth[MAXN];
int up[MAXN][LOG];
void dfs(int node, int parent)
{
    up[node][0] = parent;
    for (int i = 1; i < LOG; i++)
        if (up[node][i - 1] != -1)
            up[node][i] = up[up[node][i - 1]][i - 1];
        else
            up[node][i] = -1;
    for (int neighbor : adj[node])
        if (neighbor != parent)
        {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node);
        }
}
int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
        if ((diff >> i) & 1)
            u = up[u][i];
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    return up[u][0];
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
            adj[i].clear();
        for (int i = 0; i < N - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth[1] = 0;
        dfs(1, -1);
        int Q;
        cin >> Q;
        while (Q--)
        {
            int u, v;
            cin >> u >> v;
            int ancestor = lca(u, v);
            int distance = depth[u] + depth[v] - 2 * depth[ancestor];
            cout << distance << endl;
        }
    }
    return 0;
}