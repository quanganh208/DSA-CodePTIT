#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v, vs;
set<vector<int>> res;
bool checkPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
void Try(int i, int sum)
{
    if (checkPrime(sum))
        res.insert(vs);
    for (int j = i + 1; j <= N; j++)
    {
        vs.push_back(v[j]);
        Try(j, sum + v[j]);
        vs.pop_back();
    }
}
void solve()
{
    cin >> N;
    v.resize(N + 1, 0);
    vs.clear();
    res.clear();
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    sort(v.begin() + 1, v.end(), greater<int>());
    Try(0, 0);
    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}