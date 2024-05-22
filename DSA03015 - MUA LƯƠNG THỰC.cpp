#include <bits/stdc++.h>
using namespace std;
int minDaysToBuyFood(int N, int S, int M)
{
    if (N < M or 6 * N < 7 * M)
        return -1;
    int totalFood = S * M;
    if (totalFood % N == 0)
        return totalFood / N;
    return totalFood / N + 1;
}
void solve()
{
    int N, S, M;
    cin >> N >> S >> M;
    cout << minDaysToBuyFood(N, S, M) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}