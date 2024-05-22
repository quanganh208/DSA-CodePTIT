#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    getline(cin, s);
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != ')')
            st.push(s[i]);
        else
        {
            bool check = false;
            while (st.top() != '(')
            {
                if (st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/')
                    check = true;
                st.pop();
            }
            st.pop();
            if (!check)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    cout << "No" << endl;
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