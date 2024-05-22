#include <bits/stdc++.h>
using namespace std;
bool isCube(string a, string b)
{
    int index = 0;
    for (int i = 0; i < b.length(); i++)
        if (a[index] == b[i])
            index++;
    return (index == a.length());
}
long long findMaxCube(long long N)
{
    string strN = to_string(N);
    int numDigits = strN.length();
    for (long long i = cbrt(N); i >= 1; i--)
    {
        long long cube = i * i * i;
        string strCube = to_string(cube);
        if (isCube(strCube, strN))
            return cube;
    }
    return -1;
}
void solve()
{
    long long N;
    cin >> N;
    cout << findMaxCube(N) << endl;
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