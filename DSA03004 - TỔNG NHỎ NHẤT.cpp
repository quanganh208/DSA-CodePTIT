#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    long long num1 = 0, num2 = 0;
    for (int i = 0; i < N; i++)
        if (i & 1)
            num1 = num1 * 10 + a[i];
        else
            num2 = num2 * 10 + a[i];
    cout << num1 + num2 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}