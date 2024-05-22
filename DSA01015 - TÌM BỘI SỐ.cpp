#include <iostream>
#include <queue>
#include <string>
using namespace std;
void solve(int n)
{
    queue<string> q;
    q.push("9");
    while (!q.empty())
    {
        string s = q.front();
        q.pop();
        int x = 0;
        for (char c : s)
            x = (x * 10 + (c - '0')) % n;
        if (x == 0)
        {
            cout << s << endl;
            return;
        }
        q.push(s + '0');
        q.push(s + '9');
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}