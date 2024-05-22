#include <bits/stdc++.h>
using namespace std;
vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
void solve()
{
    int N;
    cin >> N;
    int ans = 0;
    for (int i = denominations.size() - 1; i >= 0; i--)
    {
        ans += N / denominations[i];
        N %= denominations[i];
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}