#include <bits/stdc++.h>
using namespace std;
vector<int> a;
stack<vector<int>> res;
void Try(int n)
{
    res.push(a);
    for (int i = 0; i < n; i++)
        a[i] += a[i + 1];
    a.pop_back();
    if (n > 1)
        Try(n - 1);
}
void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Try(n);
    while (!res.empty())
    {
        cout << "[";
        for (int i = 0; i < res.top().size(); i++)
            cout << res.top()[i] << (i == res.top().size() - 1 ? "" : " ");
        cout << "] ";
        res.pop();
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}