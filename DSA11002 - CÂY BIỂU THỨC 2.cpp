#include <bits/stdc++.h>
using namespace std;
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
int evaluatePrefixExpression(vector<string> expression)
{
    queue<int> operands;
    for (int i = expression.size() - 1; i >= 0; i--)
        if (isdigit(expression[i][0]))
            operands.push(stoi(expression[i]));
        else
        {
            int operand1 = operands.front();
            operands.pop();
            int operand2 = operands.front();
            operands.pop();
            operands.push(performOperation(operand2, operand1, expression[i][0]));
        }
    return operands.front();
}
void solve()
{
    int n;
    cin >> n;
    vector<string> expressions(n);
    for (int i = 0; i < n; i++)
        cin >> expressions[i];
    cout << evaluatePrefixExpression(expressions) << endl;
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