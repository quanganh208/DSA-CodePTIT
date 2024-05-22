#include <bits/stdc++.h>
using namespace std;
void Try(const vector<int> a, int i, int sum, int total, bool &flag)
{
    if (flag)
        return;
    for (int j = i; j < a.size(); j++)
    {
        sum += a[j];
        if (sum == total)
        {
            flag = true;
            return;
        }
        else if (sum < total)
            Try(a, j, sum, total, flag);
        sum -= a[j];
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int total = accumulate(a.begin(), a.end(), 0);
    if (total % 2)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        bool flag = false;
        Try(a, 0, 0, total / 2, flag);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}