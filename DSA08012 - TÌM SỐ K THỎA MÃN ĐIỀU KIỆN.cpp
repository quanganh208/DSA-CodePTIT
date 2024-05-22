#include <bits/stdc++.h>
using namespace std;
int countNumbers(int L, int R)
{
    int count = 0;
    for (int i = L; i <= R; i++)
    {
        string num = to_string(i);
        bool isDistinct = true;
        bool isLessThan5 = true;
        unordered_set<char> digits;
        for (char digit : num)
        {
            if (digits.count(digit) > 0)
            {
                isDistinct = false;
                break;
            }
            digits.insert(digit);
            if (digit > '5')
            {
                isLessThan5 = false;
                break;
            }
        }
        if (isDistinct && isLessThan5)
            count++;
    }
    return count;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    cout << countNumbers(l, r) << endl;
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