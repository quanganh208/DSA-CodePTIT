#include <bits/stdc++.h>
using namespace std;
int changeToFive(int X)
{
    int res = 0, index = 0;
    while (X)
    {
        if (X % 10 == 6)
            res += 5 * pow(10, index++);
        else
            res += (X % 10) * pow(10, index++);
        X /= 10;
    }
    return res;
}
int changeToSix(int X)
{
    int res = 0, index = 0;
    while (X)
    {
        if (X % 10 == 5)
            res += 6 * pow(10, index++);
        else
            res += (X % 10) * pow(10, index++);
        X /= 10;
    }
    return res;
}
void solve()
{
    int A, B;
    cin >> A >> B;
    cout << changeToFive(A) + changeToFive(B) << " " << changeToSix(A) + changeToSix(B);
}
int main()
{
    solve();
    return 0;
}