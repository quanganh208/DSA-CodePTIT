#include <bits/stdc++.h>
using namespace std;
void solve()
{
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "PUSH")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (s == "POP")
        {
            if (!q.empty())
                q.pop();
        }
        else if (s == "PRINTFRONT")
        {
            if (!q.empty())
                cout << q.front() << endl;
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