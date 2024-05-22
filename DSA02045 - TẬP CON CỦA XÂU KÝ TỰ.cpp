#include <bits/stdc++.h>
using namespace std;
int N;
string s;
set<string> res;
void Try(int i, string str)
{
    for (int j = i; j < s.length(); j++)
    {
        res.insert(str + s[j]);
        Try(j + 1, str + s[j]);
    }
}
void solve()
{
    res.clear();
    cin >> N >> s;
    Try(0, "");
    for (auto i : res)
        cout << i << " ";
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