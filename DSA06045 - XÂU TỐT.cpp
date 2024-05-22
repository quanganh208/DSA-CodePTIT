#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    long long res = 0, tmp = 1;
    for (int i = 1; i < n; i++)
        if (s[i] == s[i - 1])
            tmp++, res += i - (tmp <= i);
        else
            res += i - tmp, tmp = 1;
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}