#include <bits/stdc++.h>
using namespace std;
int countPairs(vector<int> Y, int x, vector<int> cnt)
{
    if (x == 0)
        return 0;
    else if (x == 1)
        return cnt[0];
    int ans = cnt[0] + cnt[1];
    int idx = upper_bound(Y.begin(), Y.end(), x) - Y.begin();
    ans += Y.size() - idx;
    if (x == 2)
        ans -= (cnt[3] + cnt[4]);
    if (x == 3)
        ans += cnt[2];
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> X(n);
    vector<int> Y(m);
    vector<int> cnt(5, 0);
    for (auto &x : X)
        cin >> x;
    for (auto &y : Y)
    {
        cin >> y;
        if (y < 5)
            cnt[y]++;
    }
    sort(Y.begin(), Y.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += countPairs(Y, X[i], cnt);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}