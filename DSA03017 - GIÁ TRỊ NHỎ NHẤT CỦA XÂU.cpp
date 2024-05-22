#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    map<char, int> m;
    for (auto i : s)
        m[i]++;
    priority_queue<int> q;
    for (auto i : m)
        q.push(i.second);
    int tmp;
    while (n--)
    {
        tmp = q.top() - 1;
        q.pop();
        q.push(tmp);
    }
    long long ans = 0;
    while (!q.empty())
    {
        ans += q.top() * q.top();
        q.pop();
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