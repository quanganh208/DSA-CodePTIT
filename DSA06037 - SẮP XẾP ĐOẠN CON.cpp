#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> arrMax(a.begin(), a.end()), arrMin(a.begin(), a.end());
    for (int i = 1; i < n; i++)
        arrMax[i] = max(arrMax[i - 1], a[i]);
    for (int i = n - 2; i >= 0; i--)
        arrMin[i] = min(arrMin[i + 1], a[i]);
    vector<int> ans;
    for (int i = 0; i < n - 1; i++)
        if (arrMax[i] <= arrMin[i + 1])
            ans.push_back(i + 1);
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
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