#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> a;
vector<int> tick;
void Try(int i)
{
    if (i > k)
    {
        for (int j = 1; j <= k; j++)
            cout << a[tick[j] - 1] << " ";
        cout << endl;
        return;
    }
    for (int j = tick[i - 1] + 1; j <= n - k + i; j++)
    {
        tick[i] = j;
        Try(i + 1);
    }
}
void solve()
{
    cin >> n >> k;
    set<string> s;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        s.insert(x);
    }
    for (auto x : s)
        a.push_back(x);
    n = a.size();
    tick.resize(k + 1, 0);
    for (int i = 1; i <= k; i++)
        tick[i] = i;
    Try(1);
}
int main()
{
    solve();
    return 0;
}