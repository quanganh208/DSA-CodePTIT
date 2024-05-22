#include <bits/stdc++.h>
using namespace std;
int BDNNumber(long long N)
{
    int cnt = 0;
    queue<long long> q;
    q.push(1);
    while (q.front() <= N)
    {
        long long x = q.front();
        q.pop();
        cnt++;
        q.push(x * 10);
        q.push(x * 10 + 1);
    }
    return cnt;
}
void solve()
{
    long long n;
    cin >> n;
    cout << BDNNumber(n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}