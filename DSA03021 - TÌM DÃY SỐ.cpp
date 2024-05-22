#include <bits/stdc++.h>
using namespace std;
bool check(int i, vector<int> v)
{
    for (auto x : v)
        if (x / i == x / (i + 1))
            return false;
    return true;
}
void solve()
{
    int n, minArr = INT_MAX;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
        minArr = min(minArr, i);
    }
    for (int i = minArr; i >= 1; i--)
        if (check(i, a))
        {
            int res = 0;
            for (auto x : a)
                res += x / (i + 1) + 1;
            cout << res << endl;
            return;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}