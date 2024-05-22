#include <bits/stdc++.h>
using namespace std;
int n;
bool check1(string s)
{
    if (*s.begin() == '8' and *s.rbegin() == '6')
        return true;
    return false;
}
bool check2(string s)
{
    for (int i = 0; i < n - 1; i++)
        if (s[i] == '8' and s[i + 1] == '8')
            return false;
    return true;
}
bool check3(string s)
{
    if (s.find("6666") != string::npos)
        return false;
    return true;
}
void Try(int i, string s)
{
    if (i == n)
    {
        if (check1(s) and check2(s) and check3(s))
            cout << s << endl;
        return;
    }
    Try(i + 1, s + "6");
    Try(i + 1, s + "8");
}
void solve()
{
    cin >> n;
    Try(0, "");
}
main()
{
    solve();
    return 0;
}