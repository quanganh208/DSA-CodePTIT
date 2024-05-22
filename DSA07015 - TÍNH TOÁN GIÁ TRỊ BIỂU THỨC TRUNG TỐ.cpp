#include <bits/stdc++.h>
using namespace std;
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
long long applyOperation(long long a, long long b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}
long long evaluateExpression(string expression)
{
    stack<long long> values;
    stack<char> operators;
    for (int i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            long long num = 0;
            while (i < expression.length() && isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        }
        else if (expression[i] == '(')
            operators.push(expression[i]);
        else if (expression[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                long long b = values.top();
                values.pop();
                long long a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            if (!operators.empty())
                operators.pop();
        }
        else
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i]))
            {
                long long b = values.top();
                values.pop();
                long long a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(expression[i]);
        }
    }
    while (!operators.empty())
    {
        long long b = values.top();
        values.pop();
        long long a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOperation(a, b, op));
    }
    return values.top();
}
void solve()
{
    string expression;
    cin >> expression;
    cout << evaluateExpression(expression) << endl;
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