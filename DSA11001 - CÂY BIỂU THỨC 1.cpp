#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return (c == '+' or c == '-' or c == '*' or c == '/');
}
bool isOperand(char c)
{
    return (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9');
}
string postfixToInfix(string postfix)
{
    stack<string> st;
    for (int i = 0; i < postfix.length(); i++)
        if (isOperand(postfix[i]))
            st.push(string(1, postfix[i]));
        else if (isOperator(postfix[i]))
        {
            string operand2 = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            string result = operand1 + postfix[i] + operand2;
            st.push(result);
        }
    return st.top();
}
void solve()
{
    string s;
    getline(cin, s);
    cout << postfixToInfix(s) << endl;
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