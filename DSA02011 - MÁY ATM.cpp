#include <bits/stdc++.h>
using namespace std;
int n, S, ans;
vector<int> t;
void Try(int i, int sum, int count)
{
    if (i == n or sum >= S or count >= ans)
    {
        if (sum == S)
            ans = min(ans, count);
        return;
    }
    Try(i + 1, sum, count);
    Try(i + 1, sum + t[i], count + 1);
}
void solve()
{
    cin >> n >> S;
    t.resize(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    ans = n + 1;
    Try(0, 0, 0);
    cout << (ans == n + 1 ? -1 : ans) << endl;
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