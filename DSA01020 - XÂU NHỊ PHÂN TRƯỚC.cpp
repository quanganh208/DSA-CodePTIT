#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string binary;
    cin >> binary;
    int n = binary.length();
    for (int i = n - 1; i >= 0; i--)
        if (binary[i] == '1')
        {
            binary[i] = '0';
            break;
        }
        else
            binary[i] = '1';
    cout << binary << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}