#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int k;
    string s;
    cin >> k >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (k == 0)
            break;
        char c = '0';
        for (int j = i + 1; j < s.length(); j++)
            c = max(c, s[j]);
        if (c <= s[i])
            continue;
        string str = s;
        for (int j = i + 1; j < s.length(); j++)
            if (s[j] == c)
            {
                string temp = s;
                swap(temp[i], temp[j]);
                str = max(str, temp);
            }
        s = str;
        k--;
    }
    cout << s << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}