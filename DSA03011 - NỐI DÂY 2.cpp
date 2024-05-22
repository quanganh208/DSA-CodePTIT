#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long minCostToConnectRopes(vector<int> &ropes)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int rope : ropes)
        minHeap.push(rope);
    long long totalCost = 0;
    while (minHeap.size() > 1)
    {
        int rope1 = minHeap.top();
        minHeap.pop();
        int rope2 = minHeap.top();
        minHeap.pop();
        int currentCost = (rope1 + rope2) % MOD;
        totalCost += currentCost;
        totalCost %= MOD;
        minHeap.push(currentCost);
    }
    return totalCost;
}
void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    cout << minCostToConnectRopes(A) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}