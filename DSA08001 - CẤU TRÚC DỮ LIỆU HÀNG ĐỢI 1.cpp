#include <bits/stdc++.h>
using namespace std;
void solve()
{
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << q.size() << endl;
            break;
        case 2:
            if (q.empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            break;
        case 3:
            int y;
            cin >> y;
            q.push(y);
            break;
        case 4:
            if (!q.empty())
                q.pop();
            break;
        case 5:
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << -1 << endl;
            break;
        case 6:
            if (!q.empty())
                cout << q.back() << endl;
            else
                cout << -1 << endl;
            break;
        default:
            break;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}