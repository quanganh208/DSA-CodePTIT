#include <bits/stdc++.h>
using namespace std;
struct State
{
    vector<int> board;
    int steps;
};
vector<int> rotateLeft(vector<int> board)
{
    vector<int> new_board = board;
    new_board[0] = board[3];
    new_board[1] = board[0];
    new_board[3] = board[4];
    new_board[4] = board[1];
    return new_board;
}
vector<int> rotateRight(vector<int> board)
{
    vector<int> new_board = board;
    new_board[1] = board[4];
    new_board[2] = board[1];
    new_board[4] = board[5];
    new_board[5] = board[2];
    return new_board;
}
int minTransformations(vector<int> start, vector<int> target)
{
    queue<State> q;
    unordered_set<string> visited;
    auto vectorToString = [](const vector<int> &v)
    {
        string s;
        for (int num : v)
            s += to_string(num) + ",";
        return s;
    };
    q.push({start, 0});
    visited.insert(vectorToString(start));
    while (!q.empty())
    {
        State current = q.front();
        q.pop();
        if (current.board == target)
            return current.steps;
        vector<int> leftRotated = rotateLeft(current.board);
        vector<int> rightRotated = rotateRight(current.board);
        string leftString = vectorToString(leftRotated);
        string rightString = vectorToString(rightRotated);
        if (visited.find(leftString) == visited.end())
        {
            q.push({leftRotated, current.steps + 1});
            visited.insert(leftString);
        }
        if (visited.find(rightString) == visited.end())
        {
            q.push({rightRotated, current.steps + 1});
            visited.insert(rightString);
        }
    }
    return -1;
}
void solve()
{
    vector<int> start(6);
    vector<int> target(6);
    for (int i = 0; i < 6; i++)
        cin >> start[i];
    for (int i = 0; i < 6; i++)
        cin >> target[i];
    cout << minTransformations(start, target) << endl;
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