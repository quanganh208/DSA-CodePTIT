#include <bits/stdc++.h>
using namespace std;
int N;
vector<bool> column, mainDiagonal, secondaryDiagonal;
vector<vector<int>> res;
vector<int> a;
bool check(int i, int j)
{
    if (column[j] == false or mainDiagonal[i - j + N - 1] == false or secondaryDiagonal[i + j] == false)
        return false;
    return true;
}
void Try(int i)
{
    for (int j = 0; j < N; j++)
        if (check(i, j))
        {
            a[i] = j;
            column[j] = false;
            mainDiagonal[i - j + N - 1] = false;
            secondaryDiagonal[i + j] = false;
            if (i == N - 1)
                res.push_back(a);
            else
                Try(i + 1);
            column[j] = true;
            mainDiagonal[i - j + N - 1] = true;
            secondaryDiagonal[i + j] = true;
        }
}
void solve()
{
    cin >> N;
    column.assign(N, true);
    mainDiagonal.assign(2 * N - 1, true);
    secondaryDiagonal.assign(2 * N - 1, true);
    a.assign(N, 0);
    res.clear();
    Try(0);
    cout << res.size() << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}