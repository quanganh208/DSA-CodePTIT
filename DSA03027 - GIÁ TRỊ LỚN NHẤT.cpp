#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans += abs(x) + x;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}