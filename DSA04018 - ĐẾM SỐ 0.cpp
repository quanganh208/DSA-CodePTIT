#include <bits/stdc++.h>
using namespace std;
int findFirstOne(vector<int> a)
{
    int low = 0, high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == 1 and (mid == 0 or a[mid - 1] == 0))
            return mid;
        else if (a[mid] == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int countZeros(vector<int> a)
{
    int firstOneIndex = findFirstOne(a);
    if (firstOneIndex == -1)
        return a.size();
    return firstOneIndex;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << countZeros(a) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}