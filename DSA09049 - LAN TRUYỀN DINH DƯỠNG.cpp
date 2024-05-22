#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> adj;
vector<long long> sum, val;
void DFS(int u)
{
    for (auto &x : adj[u])
    {
        DFS(x);
        sum[u] += sum[x] + 1;
        val[u] += val[x];
    }
    val[u] += sum[u];
}
void solve()
{
    cin >> n;
    adj.assign(n + 1, vector<int>());
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    sum.assign(n + 1, 0);
    val.assign(n + 1, 1);
    DFS(1);
    for (int i = 1; i <= n; i++)
        cout << val[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}