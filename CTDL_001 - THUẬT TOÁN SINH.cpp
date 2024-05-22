#include <bits/stdc++.h>
using namespace std;
int a[100], n;
bool isPalindrome()
{
    for (int i = 1, j = n; i < j; i++, j--)
        if (a[i] != a[j])
            return false;
    return true;
}
void Try(int m)
{
    if (m > n)
    {
        if (isPalindrome())
        {
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        a[m] = i;
        Try(m + 1);
    }
}
void solve()
{
    cin >> n;
    Try(1);
}
int main()
{
    solve();
    return 0;
}