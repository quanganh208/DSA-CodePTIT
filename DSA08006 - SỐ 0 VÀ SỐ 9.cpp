#include <bits/stdc++.h>
using namespace std;
string findSmallestNumberDivisibleByN(int N)
{
    queue<string> q;
    q.push("9");
    while (!q.empty())
    {
        string curr = q.front();
        q.pop();
        if (stoi(curr) % N == 0)
            return curr;
        q.push(curr + "0");
        q.push(curr + "9");
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << findSmallestNumberDivisibleByN(n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}