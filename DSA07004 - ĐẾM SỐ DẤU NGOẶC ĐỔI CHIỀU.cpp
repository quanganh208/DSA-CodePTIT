#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    getline(cin, s);
    stack<char> st;
    int cntBracketOpen = 0, cntBracketClose = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '(')
        {
            cntBracketOpen++;
            st.push(s[i]);
        }
        else if (!st.empty() and st.top() == '(')
        {
            cntBracketOpen--;
            st.pop();
        }
        else
        {
            cntBracketClose++;
            st.push(s[i]);
        }
    cout << cntBracketOpen / 2 + cntBracketClose / 2 + cntBracketOpen % 2 + cntBracketClose % 2 << endl;
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