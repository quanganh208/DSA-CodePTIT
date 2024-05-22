#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int K, M, N;
vector<vector<bool>> visited;
vector<string> dictionary, result;
vector<vector<char>> board;
map<string, bool> mp;
bool isValid(int x, int y)
{
    return x >= 0 && x < M && y >= 0 && y < N && !visited[x][y];
}
void Try(int x, int y, string word)
{
    if (mp[word])
        result.push_back(word);
    for (int i = 0; i < 8; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY))
        {
            visited[newX][newY] = true;
            Try(newX, newY, word + board[newX][newY]);
            visited[newX][newY] = false;
        }
    }
}
void solve()
{
    cin >> K >> M >> N;
    dictionary.resize(K);
    mp.clear();
    for (auto &word : dictionary)
    {
        cin >> word;
        mp[word] = true;
    }
    board.resize(M, vector<char>(N));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    visited.assign(M, vector<bool>(N, false));
    result.clear();
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = true;
            Try(i, j, string(1, board[i][j]));
            visited[i][j] = false;
        }
    if (result.empty())
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        for (auto &word : result)
            cout << word << " ";
        cout << endl;
    }
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