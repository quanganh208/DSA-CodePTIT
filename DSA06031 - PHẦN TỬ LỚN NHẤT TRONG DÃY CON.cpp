#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int max = INT_MIN;
    for (int i = 0; i < k; i++)
        max = max > a[i] ? max : a[i];
    for (int i = k; i < n; i++)
    {
        cout << max << " ";
        if (a[i] > max)
            max = a[i];
        else if (a[i - k] == max)
        {
            max = INT_MIN;
            for (int j = i - k + 1; j <= i; j++)
                max = max > a[j] ? max : a[j];
        }
    }
    cout << max << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}