#include <bits/stdc++.h>
using namespace std;
string change(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            if (st.top() and s[st.top() - 1] == '-')
                for (int j = st.top(); j < i; j++)
                {
                    if (s[j] == '+')
                        s[j] = '-';
                    else if (s[j] == '-')
                        s[j] = '+';
                }
            st.pop();
        }
    }
    string res = "";
    for (int i = 0; i < s.length(); i++)
        if (s[i] != '(' and s[i] != ')')
            res += s[i];
    return res;
}
void solve()
{
    string p1, p2;
    cin >> p1 >> p2;
    cout << (change(p1) == change(p2) ? "YES" : "NO") << endl;
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