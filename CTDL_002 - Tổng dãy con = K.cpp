#include <bits/stdc++.h>
using namespace std;
int a[100], tick[100], n, k, cnt = 0;
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
            for (int i = 1; i <= n; i++)
                if (tick[i])
                    cout << a[i] << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 0; i <= 1; i++)
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
    Try(1);
    cout << cnt;
}
int main()
{
    solve();
    return 0;
}