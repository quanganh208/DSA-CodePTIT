#include <bits/stdc++.h>
using namespace std;
bool isBSTInorder(vector<int> arr, int n)
{
    for (int i = 1; i < n; i++)
        if (arr[i] <= arr[i - 1])
            return false;
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    cout << isBSTInorder(arr, n) << endl;
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