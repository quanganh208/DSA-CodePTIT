#include <bits/stdc++.h>
using namespace std;
vector<int> findNearestLargerFrequency(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    unordered_map<int, int> freq;
    unordered_map<int, int> lastIndex;
    for (int i = n - 1; i >= 0; --i)
    {
        freq[arr[i]]++;
        lastIndex[arr[i]] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        int currentFreq = freq[arr[i]];
        for (int j = i + 1; j < n; ++j)
            if (freq[arr[j]] > currentFreq)
            {
                result[i] = arr[j];
                break;
            }
    }
    return result;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    vector<int> result = findNearestLargerFrequency(arr);
    for (int x : result)
        cout << x << " ";
    cout << endl;
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