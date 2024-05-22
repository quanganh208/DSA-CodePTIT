#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return (c == '+' or c == '-' or c == '*' or c == '/');
}
string postfixToPrefix(string postfix)
{
    stack<string> st;
    for (int i = 0; i < postfix.length(); i++)
        if (isOperator(postfix[i]))
        {
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            string result = postfix[i] + operand1 + operand2;
            st.push(result);
        }
        else
            st.push(string(1, postfix[i]));
    return st.top();
}
void solve()
{
    string s;
    getline(cin, s);
    cout << postfixToPrefix(s) << endl;
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