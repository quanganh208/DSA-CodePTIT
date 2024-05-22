#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v, a;
void Try(int i)
{
    for (int j = 1; j <= n; j++)
        if (!v[j])
        {
            a[i] = j;
            if (i and abs(a[i] - a[i - 1]) == 1)
                continue;
            v[j] = 1;
            if (i == n - 1)
            {
                for (int k = 0; k < n; k++)
                    cout << a[k];
                cout << endl;
            }
            else
                Try(i + 1);
            v[j] = 0;
        }
}
void solve()
{
    cin >> n;
    a.resize(n);
    v.resize(n + 1, 0);
    Try(0);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}