#include <bits/stdc++.h>
using namespace std;
int maxNonOverlappingActions(vector<pair<int, int>> actions, int N)
{
    sort(actions.begin(), actions.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    int count = 1;
    int lastEnd = actions[0].second;
    for (int i = 1; i < N; i++)
        if (actions[i].first >= lastEnd)
        {
            count++;
            lastEnd = actions[i].second;
        }
    return count;
}
void solve()
{
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i].first;
    for (int i = 0; i < N; i++)
        cin >> A[i].second;
    cout << maxNonOverlappingActions(A, N) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}