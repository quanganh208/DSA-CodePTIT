#include <bits/stdc++.h>
using namespace std;
void generateNumberMin(int n, int s)
{
    if (s > 9 * n or (s == 0 and n > 1))
    {
        cout << -1;
        return;
    }
    vector<int> res(n, 0);
    res[0] = 1;
    s -= 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = min(s, 9 - res[i]);
        res[i] += x;
        s -= x;
    }
    for (int i = 0; i < n; i++)
        cout << res[i];
}
void generateNumberMax(int n, int s)
{
    if (s > 9 * n or (s == 0 and n > 1))
    {
        cout << -1;
        return;
    }
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x = min(s, 9);
        res[i] += x;
        s -= x;
    }
    for (int i = 0; i < n; i++)
        cout << res[i];
}
void solve()
{
    int n, s;
    cin >> n >> s;
    generateNumberMin(n, s);
    cout << " ";
    generateNumberMax(n, s);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}