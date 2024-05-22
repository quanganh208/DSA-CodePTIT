#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int tmp;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[tmp] = a[tmp - 1] + 1;
    }
    cout << n - *max_element(a.begin(), a.end()) << endl;
}
int main()
{
    solve();
    return 0;
}