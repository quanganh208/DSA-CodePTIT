#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int countNumber7 = n / 7;
    int countNumber4 = n % 7;
    while (countNumber4 % 4 and countNumber7 > 0 and countNumber4 <= 28)
    {
        countNumber4 += 7;
        countNumber7--;
    }
    if (countNumber4 % 4 == 0)
    {
        for (int i = 0; i < countNumber4 / 4; i++)
            cout << 4;
        for (int i = 0; i < countNumber7; i++)
            cout << 7;
        cout << endl;
    }
    else
        cout << -1 << endl;
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