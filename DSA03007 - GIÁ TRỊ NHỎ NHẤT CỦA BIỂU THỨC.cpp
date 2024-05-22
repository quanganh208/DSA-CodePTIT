#include <bits/stdc++.h>
using namespace std;
long long findMin(vector<long long> a, vector<long long> b, int n)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<long long>());
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += a[i] * b[i];
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    cout << findMin(a, b, n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}