#include <bits/stdc++.h>
using namespace std;
string processKeystrokes(const string &keystrokes)
{
    stack<char> text;
    string result = "";
    for (char c : keystrokes)
    {
        if (c == '-')
        {
            if (!result.empty())
                result.pop_back();
        }
        else if (c == '<')
        {
            if (!result.empty())
            {
                text.push(result.back());
                result.pop_back();
            }
        }
        else if (c == '>')
        {
            if (!text.empty())
            {
                result.push_back(text.top());
                text.pop();
            }
        }
        else
            result.push_back(c);
    }
    while (!text.empty())
    {
        result.push_back(text.top());
        text.pop();
    }
    return result;
}
void solve()
{
    string keystrokes;
    cin >> keystrokes;
    cout << processKeystrokes(keystrokes);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}