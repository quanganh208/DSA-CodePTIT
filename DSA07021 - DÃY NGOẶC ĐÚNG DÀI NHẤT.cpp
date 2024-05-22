#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    getline(cin, s);
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        if (!st.empty() and s[i] == ')' and s[st.top()] == '(')
        {
            st.pop();
            ans = max(ans, i - st.top());
        }
        else
            st.push(i);
    cout << ans << endl;
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