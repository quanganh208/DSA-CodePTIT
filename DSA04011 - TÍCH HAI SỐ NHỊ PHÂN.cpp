#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    long long x = 0, y = 0;
    for (int i = 0; i < s1.size(); i++)
        x = x * 2 + (s1[i] - '0');
    for (int i = 0; i < s2.size(); i++)
        y = y * 2 + (s2[i] - '0');
    cout << x * y << endl;
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