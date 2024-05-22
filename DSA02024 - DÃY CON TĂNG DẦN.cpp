#include <bits/stdc++.h>
using namespace std;
void generateIncreasingSubsequences(vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &result)
{
    if (current.size() > 1)
        result.push_back(current);
    for (int i = start; i < nums.size(); i++)
        if (current.empty() or nums[i] > current.back())
        {
            current.push_back(nums[i]);
            generateIncreasingSubsequences(nums, i + 1, current, result);
            current.pop_back();
        }
}
vector<string> increasingSubsequences(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;
    generateIncreasingSubsequences(nums, 0, current, result);
    vector<string> resultString;
    for (auto &subsequence : result)
    {
        string subsequenceString;
        for (int num : subsequence)
            subsequenceString += to_string(num) + " ";
        resultString.push_back(subsequenceString);
    }
    return resultString;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<string> result = increasingSubsequences(nums);
    sort(result.begin(), result.end());
    for (auto subsequence : result)
        cout << subsequence << endl;
}
int main()
{
    solve();
    return 0;
}