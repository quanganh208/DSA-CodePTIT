#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
class Matrix
{
public:
    long long a[2][2];
    friend Matrix operator*(Matrix a, Matrix b)
    {
        Matrix res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    res.a[i][j] = (res.a[i][j] + a.a[i][k] * b.a[k][j] % mod) % mod;
            }
        return res;
    }
};
Matrix powMod(Matrix a, long long n)
{
    Matrix res;
    res.a[0][0] = 1;
    res.a[1][1] = 1;
    res.a[0][1] = 0;
    res.a[1][0] = 0;
    while (n)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
void solve()
{
    long long n;
    cin >> n;
    Matrix a;
    a.a[0][0] = 1;
    a.a[0][1] = 1;
    a.a[1][0] = 1;
    a.a[1][1] = 0;
    Matrix res = powMod(a, n);
    cout << res.a[0][1] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}