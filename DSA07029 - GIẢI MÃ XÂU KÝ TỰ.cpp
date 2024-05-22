#include <bits/stdc++.h>
using namespace std;
string decodeString(string str)
{
    stack<int> countStack;
    stack<string> resultStack;
    string current;
    int num = 0;
    for (char c : str)
        if (isdigit(c))
            num = num * 10 + (c - '0');
        else if (c == '[')
        {
            countStack.push(num);
            resultStack.push(current);
            current.clear();
            num = 0;
        }
        else if (c == ']')
        {
            string temp = current;
            for (int i = 1; i < countStack.top(); i++)
                current += temp;
            countStack.pop();
            current = resultStack.top() + current;
            resultStack.pop();
        }
        else
            current += c;
    return current;
}
void solve()
{
    string s;
    cin >> s;
    cout << decodeString(s) << endl;
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