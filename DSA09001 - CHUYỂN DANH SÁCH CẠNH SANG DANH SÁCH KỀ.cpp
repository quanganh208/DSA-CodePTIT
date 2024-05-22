#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v + 1, vector<int>(v + 1));
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for (int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for (int j = 1; j <= v; j++)
        {
            if (adj[i][j] == 1)
                cout << j << " ";
        }
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