#include <bits/stdc++.h>
using namespace std;
void solve()
{
    deque<int> dq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "PUSHBACK")
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "PUSHFRONT")
        {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "POPBACK")
        {
            if (!dq.empty())
                dq.pop_back();
        }
        else if (s == "POPFRONT")
        {
            if (!dq.empty())
                dq.pop_front();
        }
        else if (s == "PRINTFRONT")
        {
            if (!dq.empty())
                cout << dq.front() << endl;
            else
                cout << "NONE" << endl;
        }
        else if (s == "PRINTBACK")
        {
            if (!dq.empty())
                cout << dq.back() << endl;
            else
                cout << "NONE" << endl;
        }
    }
}
int main()
{
    solve();
    return 0;
}