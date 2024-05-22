#include <bits/stdc++.h>
using namespace std;
struct Point
{
    double x, y;
};
struct Edge
{
    int u, v;
    double weight;
};
int find(int u, vector<int> &parent)
{
    if (u != parent[u])
        parent[u] = find(parent[u], parent);
    return parent[u];
}
void union_sets(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = find(u, parent);
    v = find(v, parent);
    if (u != v)
    {
        if (rank[u] < rank[v])
            swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v])
            rank[u]++;
    }
}
double kruskal(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    double mst_weight = 0.0;
    for (Edge &edge : edges)
        if (find(edge.u, parent) != find(edge.v, parent))
        {
            mst_weight += edge.weight;
            union_sets(edge.u, edge.v, parent, rank);
        }
    return mst_weight;
}
void solve()
{
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; i++)
        cin >> points[i].x >> points[i].y;
    vector<Edge> edges;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            double weight = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
            edges.push_back({i, j, weight});
        }
    cout << fixed << setprecision(6) << kruskal(N, edges) << endl;
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