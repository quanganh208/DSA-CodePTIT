#include <bits/stdc++.h>
using namespace std;
void bfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
    }
}
int main()
{
    int K, N, M;
    cin >> K >> N >> M;
    vector<int> start_positions(K);
    for (int i = 0; i < K; i++)
        cin >> start_positions[i];
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    vector<set<int>> reachable(K);
    for (int i = 0; i < K; i++)
    {
        vector<bool> visited(N + 1, false);
        bfs(start_positions[i], adj, visited);
        for (int j = 1; j <= N; j++)
            if (visited[j])
                reachable[i].insert(j);
    }
    set<int> intersection = reachable[0];
    for (int i = 1; i < K; i++)
    {
        set<int> temp;
        for (int x : intersection)
            if (reachable[i].count(x))
                temp.insert(x);
        intersection = temp;
    }
    cout << intersection.size() << endl;
    return 0;
}