#include <bits/stdc++.h>
using namespace std;
long long BDNNumber(long long N)
{
    queue<long long> q;
    q.push(1);
    while (q.front() % N)
    {
        long long x = q.front();
        q.pop();
        q.push(x * 10);
        q.push(x * 10 + 1);
    }
    return q.front();
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