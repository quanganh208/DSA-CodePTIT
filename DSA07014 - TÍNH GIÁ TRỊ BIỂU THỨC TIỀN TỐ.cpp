#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return (c == '+' or c == '-' or c == '*' or c == '/');
}
int performOperation(int operand1, int operand2, char operation)
{
    switch (operation)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    }
}
int evaluatePrefix(string s)
{
    stack<int> st;
    for (int i = s.length() - 1; i >= 0; i--)
        if (isdigit(s[i]))
            st.push(s[i] - '0');
        else if (isOperator(s[i]))
        {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            int result = performOperation(operand1, operand2, s[i]);
            st.push(result);
        }
    return st.top();
}
void solve()
{
    string s;
    getline(cin, s);
    cout << evaluatePrefix(s) << endl;
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