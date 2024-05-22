#include <bits/stdc++.h>
using namespace std;
char c;
string s, ans;
vector<int> v;
bool check(string str)
{
    for (int i = 0; i < str.size(); i++)
        if (str[i] == 'A' or str[i] == 'E')
            if (i and str[i - 1] != 'A' and str[i - 1] != 'E')
                if (i != str.size() - 1 and str[i + 1] != 'A' and str[i + 1] != 'E')
                    return false;
    return true;
}
void Try(int i)
{
    for (int j = 0; j < s.size(); j++)
        if (!v[j])
        {
            v[j] = 1;
            ans[i] = s[j];
            if (i == s.size() - 1)
            {
                if (check(ans))
                    cout << ans << endl;
            }
            else
                Try(i + 1);
            v[j] = 0;
        }
}
void solve()
{
    cin >> c;
    for (char i = 'A'; i <= c; i++)
        s += i;
    v.resize(s.size());
    ans.resize(s.size());
    Try(0);
}
int main()
{
    solve();
    return 0;
}