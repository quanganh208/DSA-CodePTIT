#include <bits/stdc++.h>
using namespace std;
bool dynamicProgramming(vector<int> a, int s)
{
    vector<bool> dp(s + 1, false);
    dp[0] = true;
    for (int i = 0; i < a.size(); i++)
        for (int j = s; j >= a[i]; j--)
            if (dp[j - a[i]])
                dp[j] = true;
    return dp[s];
}
void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << (dynamicProgramming(a, s) ? "YES" : "NO") << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}