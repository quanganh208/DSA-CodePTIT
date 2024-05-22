#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    stack<int> st;
    while (Q--)
    {
        string s;
        cin >> s;
        if (s == "PUSH")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (s == "POP")
        {
            if (!st.empty())
                st.pop();
        }
        else if (s == "PRINT")
            if (st.empty())
                cout << "NONE" << endl;
            else
                cout << st.top() << endl;
    }
}