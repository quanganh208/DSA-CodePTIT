#include <bits/stdc++.h>
using namespace std;
int maxLength;
map<string, bool> mp;
bool isValid(string s)
{
    if (s.length() < 2)
        return false;
    stack<char> st;
    for (char c : s)
        if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            if (st.empty())
                return false;
            st.pop();
        }
    return st.empty();
}
void Try(string s, int i)
{
    if (s.length() < maxLength)
        return;
    if (isValid(s))
    {
        if (s.length() > maxLength)
        {
            maxLength = s.length();
            mp.clear();
        }
        mp[s] = true;
        return;
    }
    for (int j = i; j < s.length(); j++)
        if (s[j] == '(' || s[j] == ')')
        {
            string tmp = s;
            tmp.erase(j, 1);
            Try(tmp, j);
        }
}
void solve()
{
    string s;
    cin >> s;
    maxLength = 0;
    mp.clear();
    Try(s, 0);
    if (mp.empty())
        cout << -1 << endl;
    else
        for (auto i : mp)
            cout << i.first << " ";
    cout << endl;
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