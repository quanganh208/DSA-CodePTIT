#include <bits/stdc++.h>
using namespace std;
int apply_operator(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    return 0;
}
bool check_expression(vector<int> &nums)
{
    char ops[] = {'+', '-', '*'};
    for (char op1 : ops)
        for (char op2 : ops)
            for (char op3 : ops)
                for (char op4 : ops)
                {
                    int result = nums[0];
                    result = apply_operator(result, nums[1], op1);
                    result = apply_operator(result, nums[2], op2);
                    result = apply_operator(result, nums[3], op3);
                    result = apply_operator(result, nums[4], op4);
                    if (result == 23)
                        return true;
                }
    return false;
}
void solve()
{
    vector<int> nums(5);
    for (int i = 0; i < 5; i++)
        cin >> nums[i];
    bool found = false;
    sort(nums.begin(), nums.end());
    do
    {
        if (check_expression(nums))
        {
            found = true;
            break;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    cout << (found ? "YES" : "NO") << endl;
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