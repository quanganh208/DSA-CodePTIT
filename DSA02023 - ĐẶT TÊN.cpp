#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> a;
vector<int> tick;
void Try(int i)
{
    for (int j = tick[i - 1] + 1; j <= n - k + i; j++)
    {
        tick[i] = j;
        if (i == k)
        {
            for (int l = 1; l <= k; l++)
                cout << a[tick[l] - 1] << " ";
            cout << endl;
        }
        else
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
    Try(1);
}
int main()
{
    solve();
    return 0;
}