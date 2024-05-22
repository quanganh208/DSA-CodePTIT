#include <bits/stdc++.h>
using namespace std;
void backtrack(int idx, int currentSum, int target, vector<int> &coins, vector<int> &currentSet, int &minCoins)
{
    if (currentSum == target)
    {
        if (currentSet.size() < minCoins)
            minCoins = currentSet.size();
        return;
    }
    if (currentSum > target or idx >= coins.size() or currentSet.size() >= minCoins)
        return;
    for (int i = idx; i < coins.size(); i++)
    {
        currentSet.push_back(coins[i]);
        backtrack(i + 1, currentSum + coins[i], target, coins, currentSet, minCoins);
        currentSet.pop_back();
    }
}
int solve()
{
    int n, S;
    cin >> n >> S;
    vector<int> t(n);
    for (auto &x : t)
        cin >> x;
    sort(t.begin(), t.end(), greater<int>());
    vector<int> currentSet;
    int minCoins = INT_MAX;
    backtrack(0, 0, S, t, currentSet, minCoins);
    cout << (minCoins == INT_MAX ? -1 : minCoins);
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}