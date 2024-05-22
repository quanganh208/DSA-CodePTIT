#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (auto &i : a)
    {
        cin >> i;
        b.push_back(i);
    }
    stable_sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (a[i] == b[i])
        i++;
    while (a[j] == b[j])
        j--;
    cout << i + 1 << " " << j + 1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}