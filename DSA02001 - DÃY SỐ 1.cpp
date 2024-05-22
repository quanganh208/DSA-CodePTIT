#include <bits/stdc++.h>
using namespace std;
vector<int> a;
void Try(int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
        cout << a[i] << (i == n - 1 ? "" : " ");
    cout << "]" << endl;
    for (int i = 0; i < n; i++)
        a[i] += a[i + 1];
    if (n > 1)
        Try(n - 1);
}
void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Try(n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}