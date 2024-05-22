#include <bits/stdc++.h>
using namespace std;
int n, x;
bool cmp(int a, int b)
{
    return abs(x - a) < abs(x - b);
}
void solve()
{
    cin >> n >> x;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    stable_sort(a.begin(), a.end(), cmp);
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}