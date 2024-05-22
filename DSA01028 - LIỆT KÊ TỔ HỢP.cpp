#include <bits/stdc++.h>
using namespace std;
int n, k, a[100];
vector<int> b;
void Try(int m)
{
    if (m > k)
    {
        for (int i = 1; i <= k; i++)
            cout << b[a[i] - 1] << " ";
        cout << endl;
        return;
    }
    for (int i = a[m - 1] + 1; i <= n - k + m; i++)
    {
        a[m] = i;
        Try(m + 1);
    }
}
void solve()
{
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (auto i : s)
        b.push_back(i);
    n = b.size();
    Try(1);
    cout << endl;
}
int main()
{
    solve();
    return 0;
}