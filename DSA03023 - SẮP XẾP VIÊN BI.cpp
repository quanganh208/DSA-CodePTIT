#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s, str;
    cin >> n >> s;
    str = s;
    sort(s.begin(), s.end(), greater<char>());
    int cnt = 0;
    multiset<pair<char, char>> m;
    for (int i = 0; i < n; i++)
        if (str[i] != s[i] and m.count(make_pair(s[i], str[i])))
        {
            auto it = m.find(make_pair(s[i], str[i]));
            m.erase(it);
            cnt++;
        }
        else if (str[i] != s[i])
            m.insert(make_pair(str[i], s[i]));
    cout << cnt + ((m.size() / 3) * 2) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}