#include <bits/stdc++.h>
using namespace std;
int N, K;
int a[100], vis[100];
vector<string> v;
int res = INT_MAX;
void check()
{
    int minNum = INT_MAX, maxNum = INT_MIN;
    for (auto s : v)
    {
        string tmp = "";
        for (int i = 0; i < K; i++)
            tmp += s[a[i]];
        minNum = min(minNum, stoi(tmp));
        maxNum = max(maxNum, stoi(tmp));
    }
    res = min(res, maxNum - minNum);
}
void Try(int m)
{
    if (m == K)
    {
        check();
        return;
    }
    for (int i = 0; i < K; i++)
        if (!vis[i])
        {
            a[m] = i;
            vis[i] = 1;
            Try(m + 1);
            vis[i] = 0;
        }
}
void solve()
{
    cin >> N >> K;
    v.resize(N);
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    for (int i = 0; i < N; i++)
        cin >> v[i];
    Try(0);
    cout << res;
}
int main()
{
    solve();
    return 0;
}