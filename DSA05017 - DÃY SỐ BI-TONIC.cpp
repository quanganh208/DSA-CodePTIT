#include <bits/stdc++.h>
using namespace std;
int bitonicSum(const vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    vector<int> lis(n, 0);
    vector<int> lds(n, 0);
    lis[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lis[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] and lis[i] < lis[j] + arr[i])
                lis[i] = lis[j] + arr[i];
        }
    }
    lds[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        lds[i] = arr[i];
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] and lds[i] < lds[j] + arr[i])
                lds[i] = lds[j] + arr[i];
        }
    }
    int maxSum = lis[0] + lds[0] - arr[0];
    for (int i = 1; i < n; i++)
        maxSum = max(maxSum, lis[i] + lds[i] - arr[i]);
    return maxSum;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << bitonicSum(a) << endl;
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