#include <bits/stdc++.h>
using namespace std;
long long length[51];
int Try(int idx, long long n, long long i)
{
    long long mid = length[idx - 1] + 1;
    if (i == mid)
        return n & 1;
    else if (i < mid)
        return Try(idx - 1, n / 2, i);
    else
        return Try(idx - 1, n / 2, i - mid);
}
void solve()
{
    long long N, L, R;
    cin >> N >> L >> R;
    memset(length, 0, sizeof(length));
    int idx = 1;
    long long tmp = N;
    while (N)
    {
        length[idx] = pow(2, idx) - 1;
        N /= 2;
        idx++;
    }
    int ans = 0;
    for (long long i = L; i <= R; i++)
        ans += Try(idx - 1, tmp, i);
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