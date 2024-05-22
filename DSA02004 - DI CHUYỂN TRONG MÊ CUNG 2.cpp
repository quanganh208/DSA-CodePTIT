#include <iostream>
#include <set>
#include <string>
using namespace std;
int n;
int a[10][10], vs[10][10];
set<string> res;
void Try(int i, int j, string ans)
{
    if (a[i][j] == 0)
        return;
    if (i < 0 or i == n or j < 0 or j == n)
        return;
    if (vs[i][j])
        return;
    if (i == n - 1 and j == n - 1)
    {
        res.insert(ans);
        return;
    }
    vs[i][j] = 1;
    Try(i + 1, j, ans + "D");
    Try(i, j + 1, ans + "R");
    Try(i, j - 1, ans + "L");
    Try(i - 1, j, ans + "U");
    vs[i][j] = 0;
}
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            vs[i][j] = 0;
        }
    res.clear();
    Try(0, 0, "");
    if (!res.size())
        cout << -1;
    else
    {
        for (auto x : res)
            cout << x << " ";
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