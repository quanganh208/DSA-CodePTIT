#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> parent;
public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv)
            parent[pu] = pv;
    }
};
bool hasCycle(vector<pair<int, int>> edges, int n)
{
    DisjointSet ds(n);
    for (const auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        int pu = ds.find(u);
        int pv = ds.find(v);
        if (pu == pv)
            return true;
        ds.merge(pu, pv);
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout << (hasCycle(edges, n) ? "YES" : "NO") << endl;
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