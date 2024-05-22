#include <bits/stdc++.h>
using namespace std;
int a[100], tick[100], n, k, cnt;
void Try(int m)
{
    if (m > n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i] * tick[i];
        if (sum == k)
        {
            cnt++;
            vector<int> res;
            for (int i = 1; i <= n; i++)
                if (tick[i])
                    res.push_back(a[i]);
            cout << "[";
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << (i == res.size() - 1 ? "" : " ");
            cout << "] ";
        }
        return;
    }
    for (int i = 1; i >= 0; i--)
    {
        tick[m] = i;
        Try(m + 1);
    }
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        tick[i] = 0;
    cnt = 0;
    sort(a + 1, a + n + 1);
    Try(1);
    if (!cnt)
        cout << -1;
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