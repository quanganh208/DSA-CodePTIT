#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> a, b, c;
void Try(int i, int &res)
{
    for (int j = b[i - 1] + 1; j <= n - k + i; j++)
    {
        b[i] = j;
        c[i] = a[b[i]];
        if (i == k)
        {
            vector<int> tmp = c;
            sort(tmp.begin(), tmp.end());
            if (tmp == c)
                res++;
        }
        else
            Try(i + 1, res);
    }
}
void solve()
{
    cin >> n >> k;
    a.resize(n + 1);
    b.resize(k + 1, 0);
    c.resize(k + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 0;
    Try(1, res);
    cout << res;
}
int main()
{
    solve();
    return 0;
}