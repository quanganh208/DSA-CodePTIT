#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int euler(vector<vector<int>> adj, int v)
{
    int count = 0;
    for (int i = 1; i <= v; i++)
        if (adj[i].size() % 2)
            count++;
    return (count == 0) ? 2 : (count == 2) ? 1 : 0;
}
void solve()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v + 1, vector<int>());
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << euler(adj, v) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}