#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i <= s.length(); i++)
    {
        st.push(i + 1);
        if (i == s.length() or s[i] == 'I')
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}