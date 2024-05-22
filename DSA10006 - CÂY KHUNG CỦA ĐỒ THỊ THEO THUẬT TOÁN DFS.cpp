#include <bits/stdc++.h>
using namespace std;
void DFS(int node, vector<bool> &visited, vector<int> adj[], vector<pair<int, int>> &parent)
{
    stack<int> st;
    st.push(node);
    visited[node] = true;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        for (int i : adj[curr])
        {
            if (!visited[i])
            {
                visited[i] = true;
                st.push(curr);
                st.push(i);
                parent.push_back({curr, i});
                break;
            }
        }
    }
}
void constructMST(int v, int u, vector<int> adj[])
{
    vector<bool> visited(v + 1, false);
    vector<pair<int, int>> parent;
    DFS(u, visited, adj, parent);
    if (parent.size() != v - 1)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= v; i++)
        if (!visited[i])
        {
            cout << -1 << endl;
            return;
        }
    for (auto i : parent)
        cout << i.first << " " << i.second << endl;
}
void solve()
{
    int v, e, u;
    cin >> v >> e >> u;
    vector<int> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    constructMST(v, u, adj);
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