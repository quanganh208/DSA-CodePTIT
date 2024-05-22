#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int m = n;
    while (m--)
        for (int i = 0; i < n - m; i++)
            if (a[i] < a[i + m])
            {
                cout << m << endl;
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