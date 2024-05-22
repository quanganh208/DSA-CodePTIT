#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int k;
    string s;
    cin >> k >> s;
    map<char, int> mp;
    priority_queue<int> pq;
    for (char c : s)
        mp[c]++;
    for (auto p : mp)
        pq.push(p.second);
    while (k--)
    {
        int x = pq.top();
        pq.pop();
        pq.push(x - 1);
    }
    long long ans = 0;
    while (!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        ans += 1LL * x * x;
    }
    cout << ans << endl;
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