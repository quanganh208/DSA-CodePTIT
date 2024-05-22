#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    for (char ch : s)
        if (ch != ')')
            st.push(ch);
        else
        {
            string tmp = "";
            while (st.top() != '(')
            {
                tmp = st.top() + tmp;
                st.pop();
            }
            st.pop();
            if (!st.empty() and st.top() == '-')
            {
                for (char c : tmp)
                {
                    if (c == '+')
                        c = '-';
                    else if (c == '-')
                        c = '+';
                    st.push(c);
                }
            }
            else
            {
                for (char c : tmp)
                    st.push(c);
            }
        }
    string res = "";
    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }
    cout << res << endl;
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