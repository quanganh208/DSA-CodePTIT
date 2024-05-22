#include <bits/stdc++.h>
using namespace std;
int n, k, cnt;
vector<string> res;
bool check(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int count = 0;
        while (s[i] == 'A')
        {
            count++;
            i++;
        }
        if (count == k)
            cnt++;
    }
    if (cnt == 1)
        return true;
    return false;
}
void Try(int i, string s)
{
    if (i == n)
    {
        if (check(s))
        {
            cnt++;
            res.push_back(s);
        }
        return;
    }
    Try(i + 1, s + "A");
    Try(i + 1, s + "B");
}
void solve()
{
    cin >> n >> k;
    cnt = 0;
    Try(0, "");
    cout << cnt << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
}
int main()
{
    solve();
    return 0;
}