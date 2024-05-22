#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    int cur = a[0].second;
    int cnt = 1;
    for (int i = 1; i < N; i++)
        if (a[i].first >= cur)
        {
            cur = a[i].second;
            cnt++;
        }
        else
            cur = min(cur, a[i].second);
    cout << cnt << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}