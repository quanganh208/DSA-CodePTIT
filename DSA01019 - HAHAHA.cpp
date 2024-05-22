#include <bits/stdc++.h>
using namespace std;
void Try(int n, string ans)
{
    if (n == 0)
    {
        if (*ans.begin() == 'H' and *ans.rbegin() == 'A')
        {
            bool isValid = true;
            for (int i = 0; i < ans.size() - 1; i++)
                if (ans[i] == 'H' and ans[i + 1] == 'H')
                {
                    isValid = false;
                    break;
                }
            if (isValid)
                cout << ans << endl;
        }
        return;
    }
    Try(n - 1, ans + 'A');
    Try(n - 1, ans + 'H');
}
void solve()
{
    int n;
    cin >> n;
    Try(n, "");
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}