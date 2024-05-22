#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> parent, leafNode;
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto i : adj[v])
        {
            parent[i] = v;
            if (adj[i].empty())
                leafNode.push_back(i);
            else
                q.push(i);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    parent.assign(n + 1, 0);
    leafNode.clear();
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    BFS(1);
    sort(leafNode.begin(), leafNode.end());
    for (auto x : leafNode)
    {
        stack<int> st;
        st.push(x);
        while (x != 1)
        {
            x = parent[x];
            st.push(x);
        }
        while (st.size())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
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