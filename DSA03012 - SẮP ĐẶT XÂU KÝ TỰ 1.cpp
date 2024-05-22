#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto i : s)
        mp[i]++;
    int max = max_element(mp.begin(), mp.end(), [](auto a, auto b)
                          { return a.second < b.second; })
                  ->second;
    if (max > (s.size() + 1) / 2)
        cout << "-1" << endl;
    else
        cout << "1" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}