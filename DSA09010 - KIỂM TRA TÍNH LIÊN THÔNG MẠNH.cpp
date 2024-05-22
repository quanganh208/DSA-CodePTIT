#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void DFS(vector<vector<int>> adj, int s, vector<bool> &visited)
{
    stack<int> st;
    st.push(s);
    visited[s] = true;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        for (int v : adj[u])
            if (!visited[v])
            {
                visited[v] = true;
                st.push(u);
                st.push(v);
                break;
            }
    }
}
bool strongConnected(vector<vector<int>> adj, int v)
{
    for (int i = 1; i <= v; i++)
    {
        vector<bool> visited(v + 1, false);
        DFS(adj, i, visited);
        for (int j = 1; j <= v; j++)
            if (!visited[j])
                return false;
    }
    return true;
}
void solve()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v + 1);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cout << (strongConnected(adj, v) ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}