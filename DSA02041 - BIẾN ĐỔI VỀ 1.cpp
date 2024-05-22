#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N;
    cin >> N;
    int ans = INT_MAX;
    queue<pair<int, int>> q;
    q.push({N, 0});
    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        if (front.first == 1)
        {
            cout << front.second << endl;
            return;
        }
        if (front.first % 3 == 0)
            q.push({front.first / 3, front.second + 1});
        if (front.first % 2 == 0)
            q.push({front.first / 2, front.second + 1});
        q.push({front.first - 1, front.second + 1});
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