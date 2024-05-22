#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    map<int, bool> mp;
    cin >> n >> k;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        mp[a[i]] = true;
    }
    int i = k;
    while (i > 0 and a[i] == n - k + i)
        i--;
    int count = 0;
    if (i > 0)
        a[i]++;
    else
    {
        cout << k << endl;
        return;
    }
    for (int j = i + 1; j <= k; j++)
        a[j] = a[i] + j - i;
    for (int i = 1; i <= k; i++)
        if (!mp[a[i]])
            count++;
    cout << count << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}