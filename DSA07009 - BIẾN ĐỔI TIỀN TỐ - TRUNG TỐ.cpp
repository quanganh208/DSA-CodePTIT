#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return (c == '+' or c == '-' or c == '*' or c == '/');
}
string prefixToInfix(string s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--)
        if (isOperator(s[i]))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = "(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        }
        else
            st.push(string(1, s[i]));
    return st.top();
}
void solve()
{
    string s;
    getline(cin, s);
    cout << prefixToInfix(s) << endl;
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