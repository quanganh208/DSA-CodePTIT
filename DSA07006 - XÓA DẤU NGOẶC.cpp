#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int>> brackets;
vector<string> binaryStrings;
void generateBinaryStrings(string &s, int index)
{
    if (index == s.size())
    {
        binaryStrings.push_back(s);
        return;
    }
    s[index] = '0';
    generateBinaryStrings(s, index + 1);
    s[index] = '1';
    generateBinaryStrings(s, index + 1);
}
string removeBrackets(string s, string example)
{
    vector<bool> flag(s.size(), true);
    for (int i = 0; i < example.size(); i++)
        if (example[i] == '0')
            flag[brackets[i].first] = flag[brackets[i].second] = false;
    string res = "";
    for (int i = 0; i < s.size(); i++)
        if (flag[i])
            res += s[i];
    return res;
}
void solve()
{
    string s;
    cin >> s;
    stack<pair<int, int>> st;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '(')
        {
            brackets[count].first = i;
            st.push({count++, i});
        }
        else if (s[i] == ')')
        {
            brackets[st.top().first].second = i;
            st.pop();
        }
    string tmp = string(count, '0');
    generateBinaryStrings(tmp, 0);
    binaryStrings.pop_back();
    map<string, bool> res;
    for (int i = 0; i < binaryStrings.size(); i++)
        res[removeBrackets(s, binaryStrings[i])] = true;
    for (auto i : res)
        cout << i.first << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}