#include <bits/stdc++.h>
using namespace std;
bool checkNgto(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
void solve()
{
    int N;
    cin >> N;
    bool flag = false;
    for (int i = 2; i <= sqrt(N); i++)
        if (checkNgto(i) && checkNgto(N - i))
        {
            cout << i << " " << N - i << endl;
            flag = true;
            break;
        }
    if (!flag)
        cout << -1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}