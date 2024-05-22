#include <iostream>
using namespace std;
int n, k, s, ans;
int a[20];
void Try(int i)
{
    for (int j = a[i - 1] + 1; j <= n - k + i; ++j)
    {
        a[i] = j;
        if (i == k)
        {
            int sum = 0;
            for (int l = 1; l <= k; ++l)
                sum += a[l];
            if (sum == s)
                ans++;
        }
        else
            Try(i + 1);
    }
}
void solve()
{
    if (n == 0 and k == 0 and s == 0)
        return;
    ans = 0;
    Try(1);
    cout << ans << endl;
}
int main()
{
    do
    {
        cin >> n >> k >> s;
        solve();
    } while (n and k and s);
    return 0;
}