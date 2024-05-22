#include <iostream>
#include <vector>
#include <string>
using namespace std;
int countDecodings(const string message)
{
    int n = message.length();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
        if (message[i] == '0')
            dp[i] = 0;
        else
        {
            dp[i] = dp[i + 1];
            if (i + 1 < n and ((message[i] == '1') or (message[i] == '2' and message[i + 1] <= '6')))
                dp[i] += dp[i + 2];
        }
    return dp[0];
}
void solve()
{
    string message;
    cin >> message;
    cout << countDecodings(message) << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}