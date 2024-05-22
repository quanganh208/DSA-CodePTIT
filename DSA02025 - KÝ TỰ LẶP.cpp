#include <bits/stdc++.h>
using namespace std;
int n, res;
string a[11], tmp[11];
bool vs[11];
void Try(int i, int count)
{
    if (i > n)
    {
        res = min(res, count);
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!vs[j])
        {
            vs[j] = true;
            tmp[i] = a[j];
            int countArr[127] = {0};
            for (char c : tmp[i])
                countArr[c]++;
            for (char c : tmp[i - 1])
                countArr[c]++;
            int cnt = 0;
            for (int i = 'A'; i <= 'Z'; ++i)
                if (countArr[i] == 2)
                    cnt++;
            if (count + cnt < res)
                Try(i + 1, count + cnt);
            vs[j] = false;
        }
}
void solve()
{
    res = INT_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(1, 0);
    cout << res;
}
int main()
{
    solve();
    return 0;
}