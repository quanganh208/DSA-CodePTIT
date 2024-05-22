#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    return (c == '+' or c == '-' or c == '*' or c == '/' or c == '^');
}
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string infix)
{
    stack<char> operatorStack;
    string postfix;
    for (int i = 0; i < infix.length(); i++)
        if (isalnum(infix[i]))
            postfix += infix[i];
        else if (infix[i] == '(')
            operatorStack.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (!operatorStack.empty() and operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (isOperator(infix[i]))
        {
            while (!operatorStack.empty() and precedence(operatorStack.top()) >= precedence(infix[i]))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(infix[i]);
        }
    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    return postfix;
}
void solve()
{
    string s;
    getline(cin, s);
    cout << infixToPostfix(s) << endl;
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