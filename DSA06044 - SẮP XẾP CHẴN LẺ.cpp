#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i % 2)
            odd.push_back(x);
        else
            even.push_back(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), greater<int>());
    for (int i = 0; i < n / 2; i++)
        cout << odd[i] << " " << even[i] << " ";
    if (n % 2)
        cout << odd[n / 2];
}
int main()
{
    solve();
    return 0;
}