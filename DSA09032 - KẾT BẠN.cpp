#include <bits/stdc++.h>
using namespace std;
int findParent(int x, vector<int> &parent)
{
    if (parent[x] != x)
        parent[x] = findParent(parent[x], parent);
    return parent[x];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    vector<int> size(n + 1, 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int parentA = findParent(a, parent);
        int parentB = findParent(b, parent);
        if (parentA != parentB)
        {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        }
    }
    int maxSize = 0;
    for (int i = 1; i <= n; i++)
        if (parent[i] == i && size[i] > maxSize)
            maxSize = size[i];
    cout << maxSize << endl;
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