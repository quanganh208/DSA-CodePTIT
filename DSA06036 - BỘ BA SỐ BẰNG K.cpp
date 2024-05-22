#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] + a[i + 1] > k)
            break;
        for (int j = i + 1; j < n - 1; j++)
            if (binary_search(a.begin() + j + 1, a.end(), k - a[i] - a[j]))
            {
                cout << "YES" << endl;
                return;
            }
    }
    cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}