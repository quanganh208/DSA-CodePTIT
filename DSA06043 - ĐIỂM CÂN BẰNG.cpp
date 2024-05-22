#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> res({0});
    for (auto &x : a)
    {
        cin >> x;
        res.push_back(*res.rbegin() + x);
    }
    for (int i = 1; i < n; i++)
        if (res[i] == res[n] - res[i + 1])
        {
            cout << i + 1 << endl;
            return;
        }
    cout << -1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}