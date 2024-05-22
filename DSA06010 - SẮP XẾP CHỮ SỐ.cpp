#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, x;
    cin >> n;
    map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (x)
        {
            m[x % 10] = true;
            x /= 10;
        }
    }
    for (int i = 0; i < 10; i++)
        if (m[i])
            cout << i << " ";
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