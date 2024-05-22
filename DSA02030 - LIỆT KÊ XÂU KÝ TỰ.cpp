#include <bits/stdc++.h>
using namespace std;
char c;
int k;
string s;
void Try(int i)
{
    if (i == k)
    {
        cout << s << endl;
        return;
    }
    for (char j = 'A'; j <= c; j++)
    {
        if (i > 0 and s[i - 1] > j)
            continue;
        s[i] = j;
        Try(i + 1);
    }
}
void solve()
{
    cin >> c >> k;
    s.resize(k);
    Try(0);
}
int main()
{
    solve();
    return 0;
}