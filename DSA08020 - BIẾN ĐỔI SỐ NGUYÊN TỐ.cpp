#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}
int bfs(int start, int target)
{
    queue<int> q;
    vector<bool> visited(10000, false);
    vector<int> dist(10000, 0);
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == target)
            return dist[curr];
        for (int i = 0; i < 4; i++)
        {
            int digit = (curr / (int)pow(10, i)) % 10;
            for (int j = 0; j <= 9; j++)
            {
                int next = curr + (j - digit) * (int)pow(10, i);
                if (next >= 1000 && isPrime(next) && !visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                    dist[next] = dist[curr] + 1;
                }
            }
        }
    }
    return -1;
}
void solve()
{
    int start, target;
    cin >> start >> target;
    cout << bfs(start, target) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}