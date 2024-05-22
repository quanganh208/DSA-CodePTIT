#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int s, d;
    cin >> s >> d;
    if (s > 9 * d)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> res(d, 0);
    res[0] = 1;
    s -= 1;
    for (int i = d - 1; i >= 0; i--)
    {
        int x = min(s, 9 - res[i]);
        res[i] += x;
        s -= x;
    }
    for (int i = 0; i < d; i++)
        cout << res[i];
    cout << endl;
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