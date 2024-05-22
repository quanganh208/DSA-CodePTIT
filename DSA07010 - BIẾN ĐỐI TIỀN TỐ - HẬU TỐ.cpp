#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return (c == '+' or c == '-' or c == '*' or c == '/');
}
bool isOperand(char c)
{
    return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z');
}
string prefixToPostfix(string s)
{
    stack<string> st;
    int length = s.size();
    for (int i = s.size() - 1; i >= 0; i--)
        if (isOperand(s[i]))
            st.push(string(1, s[i]));
        else if (isOperator(s[i]))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = op1 + op2 + s[i];
            st.push(temp);
        }
    return st.top();
}
void solve()
{
    string s;
    getline(cin, s);
    cout << prefixToPostfix(s) << endl;
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