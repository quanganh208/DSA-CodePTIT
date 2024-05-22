#include <bits/stdc++.h>
using namespace std;
string nextPermutation(string s)
{
    int idx = s.length() - 2;
    while (idx >= 0 and s[idx] >= s[idx + 1])
        idx--;
    if (idx < 0)
        return "BIGGEST";
    int idx2 = s.length() - 1;
    while (s[idx2] <= s[idx])
        idx2--;
    swap(s[idx], s[idx2]);
    reverse(s.begin() + idx + 1, s.end());
    return s;
}
void solve()
{
    int t;
    string s;
    cin >> t >> s;
    cout << t << " " << nextPermutation(s) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}