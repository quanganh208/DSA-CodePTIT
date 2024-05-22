#include <bits/stdc++.h>
using namespace std;
vector<int> a, ans;
int current = 0, x;
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
            cout << "[";
            for (int k = 0; k < ans.size(); k++)
                if (k == ans.size() - 1)
                    cout << ans[k];
                else
                    cout << ans[k] << " ";
            cout << "]";
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
    current = 0;
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