#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> visited;
vector<vector<int>> graph;
int answer = 0;
void dfs(int u, int length = 0)
{
    answer = max(answer, length);
    for (int v : graph[u])
    {
        if (!visited[u][v])
        {
            visited[u][v] = visited[v][u] = true;
            dfs(v, length + 1);
            visited[u][v] = visited[v][u] = false;
        }
    }
}
void solve()
{
    int N, M;
    cin >> N >> M;
    graph.clear();
    graph.resize(N + 1);
    visited.assign(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    answer = 0;
    for (int i = 0; i < N; i++)
        dfs(i);
    cout << answer << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}