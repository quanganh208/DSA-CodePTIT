#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n - 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (int i = 0; i < n - 1; i++)
        if (a[i] != b[i])
        {
            cout << i + 1 << endl;
            return;
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