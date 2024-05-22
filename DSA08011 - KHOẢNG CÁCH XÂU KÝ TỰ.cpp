#include <bits/stdc++.h>
using namespace std;
// Kiểm tra xem từ mới được sinh ra từ từ gốc có trong danh sách từ hay không
bool isValidWord(const string &word, const unordered_set<string> &wordSet)
{
    return wordSet.find(word) != wordSet.end();
}
// Tìm khoảng cách ngắn nhất từ s đến t
int shortestPathLength(const vector<string> &words, const string &s, const string &t)
{
    unordered_set<string> wordSet(words.begin(), words.end());
    if (wordSet.find(t) == wordSet.end())
        return -1; // t không có trong từ điển
    queue<pair<string, int>> q; // pair<word, distance>
    q.push({s, 1});
    wordSet.erase(s);
    while (!q.empty())
    {
        auto [currentWord, distance] = q.front();
        q.pop();
        if (currentWord == t)
            return distance;
        for (int i = 0; i < currentWord.size(); i++)
        {
            char originalChar = currentWord[i];
            for (char c = 'A'; c <= 'Z'; c++)
            {
                if (c == originalChar)
                    continue;
                currentWord[i] = c;
                if (isValidWord(currentWord, wordSet))
                {
                    q.push({currentWord, distance + 1});
                    wordSet.erase(currentWord);
                }
            }
            currentWord[i] = originalChar;
        }
    }
    return -1; // không tìm thấy đường đi
}
void solve()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<string> words(n);
    for (string &word : words)
        cin >> word;
    cout << shortestPathLength(words, s, t) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}