#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    map<long long, long long> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    long long cnt = 0;
    for (auto i : mp)
        if (i.first * 2 == k)
            cnt += i.second * (i.second - 1);
        else
            cnt += i.second * mp[k - i.first];
    cout << cnt / 2 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}