#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<long long> ans = {a[0] * a[1], a[0] * a[1] * a[N - 1], a[N - 1] * a[N - 2], a[N - 1] * a[N - 2] * a[N - 3]};
    cout << *max_element(ans.begin(), ans.end()) << endl;
}
int main()
{
    solve();
    return 0;
}