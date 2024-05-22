#include <bits/stdc++.h>
using namespace std;
void HaNoiTower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    HaNoiTower(n - 1, a, c, b);
    HaNoiTower(1, a, b, c);
    HaNoiTower(n - 1, b, a, c);
}
int main()
{
    int N;
    cin >> N;
    HaNoiTower(N, 'A', 'B', 'C');
}