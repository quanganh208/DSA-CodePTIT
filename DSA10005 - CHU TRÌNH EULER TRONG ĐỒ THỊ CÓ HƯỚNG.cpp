#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool eulerCycle(vector<vector<int>> adj, int v)
{
    vector<int> in(v + 1, 0), out(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        out[i] = adj[i].size();
        for (int j = 0; j < adj[i].size(); j++)
            in[adj[i][j]]++;
    }
    for (int i = 1; i <= v; i++)
        if (in[i] != out[i])
            return false;
    return true;
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
    }
    cout << eulerCycle(adj, v) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}