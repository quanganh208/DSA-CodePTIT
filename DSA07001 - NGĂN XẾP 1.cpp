#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    stack<int> st;
    while (cin >> s)
    {
        if (s == "push")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (s == "pop")
        {
            if (st.empty())
                cout << "empty" << endl;
            else
                st.pop();
        }
        else if (s == "show")
        {
            if (st.empty())
                cout << "empty" << endl;
            else
            {
                stack<int> temp = st;
                vector<int> v;
                while (!temp.empty())
                {
                    v.push_back(temp.top());
                    temp.pop();
                }
                for (int i = v.size() - 1; i >= 0; i--)
                    cout << v[i] << " ";
                cout << endl;
            }
        }
    }
}