#include <bits/stdc++.h>
using namespace std;
int maxSegments = 1;
vector<map<int, int>> dp;
bool isValid(int length, int x, int y)
{
    auto it = dp[length].lower_bound(x);
    if (it == dp[length].begin())
        return false;
    it--;
    return it->second < y;
}
void insertSegment(int length, int x, int y)
{
    auto it = dp[length].lower_bound(x);
    auto temp = it;
    while (it != dp[length].end() and it->second >= y)
        it++;
    dp[length].erase(temp, it);
    dp[length].insert({x, y});
}
void solve()
{
    int numberOfSegments;
    cin >> numberOfSegments;
    dp.resize(numberOfSegments + 1);
    insertSegment(0, INT_MIN, INT_MIN);
    while (numberOfSegments--)
    {
        int x, y;
        cin >> x >> y;
        int left = 0, right = maxSegments;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (isValid(mid, x, y))
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (maxSegments == left - 1)
            maxSegments++;
        insertSegment(left, x, y);
    }
    cout << maxSegments;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}