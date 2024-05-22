#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> a, ans;
void Try(int i)
{
    for (int j = i; j < N; j++)
    {
        ans.push_back(a[j]);
        if (ans.size() == K)
        {
            for (int x : ans)
                cout << x << " ";
            cout << endl;
        }
        else
            Try(j + 1);
        ans.pop_back();
    }
}
void solve()
{
    cin >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    Try(0);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}