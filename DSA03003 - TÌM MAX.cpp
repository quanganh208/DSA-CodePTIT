#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    long long max = 0;
    for (int i = 0; i < N; i++)
    {
        max += (a[i] * i);
        max %= (long long)(1e9 + 7);
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