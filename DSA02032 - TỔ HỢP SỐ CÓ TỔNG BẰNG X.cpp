#include <bits/stdc++.h>
using namespace std;
vector<int> a, ans;
vector<vector<int>> res;
int current, x, cnt;
bool check = false;
void Try(int i)
{
    for (int j = i; j < a.size(); j++)
    {
        current += a[j];
        ans.push_back(a[j]);
        if (current == x)
        {
            check = true;
            cnt++;
            res.push_back(ans);
        }
        else if (current < x)
            Try(j);
        current -= a[j];
        ans.pop_back();
    }
}
void solve()
{
    a.clear();
    ans.clear();
    res.clear();
    current = cnt = 0;
    check = false;
    int n;
    cin >> n >> x;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    for (auto i : s)
        a.push_back(i);
    Try(0);
    if (!check)
        cout << -1;
    else
    {
        cout << cnt << " ";
        for (int i = 0; i < res.size(); i++)
        {
            cout << "{";
            for (int k = 0; k < res[i].size(); k++)
                if (k == res[i].size() - 1)
                    cout << res[i][k];
                else
                    cout << res[i][k] << " ";
            cout << "} ";
        }
    }
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