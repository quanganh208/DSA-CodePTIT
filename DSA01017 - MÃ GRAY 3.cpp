#include <bits/stdc++.h>
using namespace std;
string binarytoGray(string binary)
{
    string gray = "";
    gray += binary[0];
    for (int i = 1; i < binary.length(); i++)
        gray += (binary[i - 1] == binary[i]) ? '0' : '1';
    return gray;
}
void solve()
{
    string s;
    cin >> s;
    cout << binarytoGray(s) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}