#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int maxN = 1005;
int n, m;
vector<int> adj[maxN];
bool visited[maxN];
void bfs(int u, int x, int y)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < adj[v].size(); i++)
        {
            int w = adj[v][i];
            if (!visited[w] and (v != x or w != y) and (v != y or w != x))
            {
                visited[w] = true;
                q.push(w);
            }
        }
    }
}
int countConnectedComponent(int x, int y)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!visited[i])
        {
            bfs(i, x, y);
            cnt++;
        }
    return cnt;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    fill(visited, visited + maxN, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << countConnectedComponent(-1, -1) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}