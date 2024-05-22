#include <bits/stdc++.h>
using namespace std;
vector<long long> G({0, 1});
void init()
{
    for (int i = 2; i < 93; i++)
        G.push_back(G[i - 1] + G[i - 2]);
}
void Try(int n, long long i)
{
    if (n == 1)
        cout << "A" << endl;
    else if (n == 2)
        cout << "B" << endl;
    else if (i <= G[n - 2])
        Try(n - 2, i);
    else
        Try(n - 1, i - G[n - 2]);
}
void solve()
{
    int n;
    long long i;
    cin >> n >> i;
    Try(n, i);
}
int main()
{
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}