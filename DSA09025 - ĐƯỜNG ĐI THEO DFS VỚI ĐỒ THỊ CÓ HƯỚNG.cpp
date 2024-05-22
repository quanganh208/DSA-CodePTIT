#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void DFS(vector<vector<int>> adj, vector<bool> &visited, vector<int> &mark, int s, int t)
{
    stack<int> st;
    st.push(s);
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (u == t)
            return;
        if (!adj.empty())
            for (int i = 0; i < adj[u].size(); i++)
                if (!visited[adj[u][i]])
                {
                    st.push(u);
                    st.push(adj[u][i]);
                    visited[adj[u][i]] = true;
                    mark[adj[u][i]] = u;
                    break;
                }
    }
}
void solve()
{
    int v, e, s, t;
    cin >> v >> e >> s >> t;
    vector<vector<int>> adj(v + 1, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<bool> visited(v + 1, false);
    vector<int> mark(v + 1, -1);
    visited[s] = true;
    DFS(adj, visited, mark, s, t);
    if (mark[t] == -1)
        cout << -1 << endl;
    else
    {
        vector<int> res;
        res.push_back(t);
        while (mark[t] != -1)
        {
            res.push_back(mark[t]);
            t = mark[t];
        }
        for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << " ";
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}