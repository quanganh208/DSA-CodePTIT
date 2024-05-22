#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int type;
    for (auto &i : a)
        cin >> i;
    int min = INT_MAX, ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (abs(a[i] + a[j]) < min)
            {
                min = abs(a[i] + a[j]);
                ans = a[i] + a[j];
            }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}