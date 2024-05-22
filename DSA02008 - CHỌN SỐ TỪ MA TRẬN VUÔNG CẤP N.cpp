#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &i : a)
        for (auto &j : i)
            cin >> j;
    vector<int> x(n);
    vector<vector<int>> ans;
    int curr = 0;
    for (int i = 0; i < n; i++)
        x[i] = i + 1;
    for (int i = 0; i < n; i++)
        curr += a[i][x[i] - 1];
    if (curr == k)
        ans.push_back(x);
    while (next_permutation(x.begin(), x.end()))
    {
        curr = 0;
        for (int i = 0; i < n; i++)
            curr += a[i][x[i] - 1];
        if (curr == k)
            ans.push_back(x);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}