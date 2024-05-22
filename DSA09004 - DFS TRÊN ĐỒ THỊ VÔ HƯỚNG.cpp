#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> adj, int v, int u)
{
    stack<int> st;
    vector<bool> visited(v + 1, false);
    st.push(u);
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }
        for (int i = 1; i <= v; i++)
            if (adj[s][i] and !visited[i])
            {
                st.push(s);
                st.push(i);
                break;
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
        adj[b][a] = 1;
    }
    DFS(adj, v, u);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}