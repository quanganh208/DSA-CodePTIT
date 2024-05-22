#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> left(n);
    vector<int> right(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            left[i] = 0;
        else
            left[i] = s.top() + 1;
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (s.empty())
            right[i] = n - 1;
        else
            right[i] = s.top() - 1;
        s.push(i);
    }
    long long res = 0;
    for (int i = 0; i < n; i++)
        if (a[i] <= right[i] - left[i] + 1)
            res = max(res, (long long)a[i]);
    cout << res << endl;
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