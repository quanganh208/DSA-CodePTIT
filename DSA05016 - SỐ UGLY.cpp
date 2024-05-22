#include <bits/stdc++.h>
using namespace std;
int getUglyNumber(int n)
{
    vector<int> uglyNumbers(1, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;
    for (int i = 1; i < n; i++)
    {
        int nextUglyNumber = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
        uglyNumbers.push_back(nextUglyNumber);
        if (nextUglyNumber == next_multiple_of_2)
            next_multiple_of_2 = uglyNumbers[++i2] * 2;
        if (nextUglyNumber == next_multiple_of_3)
            next_multiple_of_3 = uglyNumbers[++i3] * 3;
        if (nextUglyNumber == next_multiple_of_5)
            next_multiple_of_5 = uglyNumbers[++i5] * 5;
    }
    return uglyNumbers.back();
}
void solve()
{
    int n;
    cin >> n;
    cout << getUglyNumber(n) << endl;
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