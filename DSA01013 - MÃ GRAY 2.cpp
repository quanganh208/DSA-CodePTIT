#include <bits/stdc++.h>
using namespace std;
string graytoBinary(string gray)
{
    string binary = "";
    binary += gray[0];
    for (int i = 1; i < gray.length(); i++)
        if (gray[i] == '0')
            binary += binary[i - 1];
        else
            binary += (binary[i - 1] == '0') ? '1' : '0';
    return binary;
}
void solve()
{
    string s;
    cin >> s;
    cout << graytoBinary(s) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}