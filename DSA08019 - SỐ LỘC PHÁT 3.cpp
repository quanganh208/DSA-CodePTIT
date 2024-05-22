#include <bits/stdc++.h>
using namespace std;
vector<string> genNumber(int N)
{
    vector<string> res;
    queue<string> q;
    q.push("6");
    q.push("8");
    while (q.front().size() <= N)
    {
        string x = q.front();
        q.pop();
        res.push_back(x);
        q.push(x + "6");
        q.push(x + "8");
    }
    reverse(res.begin(), res.end());
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vector<string> res = genNumber(n);
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}