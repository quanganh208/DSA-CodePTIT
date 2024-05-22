#include <bits/stdc++.h>
using namespace std;
bool checkBracket(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' or s[i] == '[' or s[i] == '{')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            if (s[i] == ')' and st.top() != '(')
                return false;
            if (s[i] == ']' and st.top() != '[')
                return false;
            if (s[i] == '}' and st.top() != '{')
                return false;
            st.pop();
        }
    }
    return st.empty();
}
void solve()
{
    string s;
    getline(cin, s);
    cout << (checkBracket(s) ? "YES" : "NO") << endl;
}
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
        solve();
    return 0;
}