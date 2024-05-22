#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s)
        if (!st.empty() and c == ')' and st.top() == '(')
            st.pop();
        else
            st.push(c);
    cout << s.length() - st.size() << endl;
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