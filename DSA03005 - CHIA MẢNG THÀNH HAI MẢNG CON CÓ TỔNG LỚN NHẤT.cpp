#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &x : A)
        cin >> x;
    K = min(K, N - K);
    sort(A.begin(), A.end());
    int sum1 = accumulate(A.begin(), A.begin() + K, 0);
    int sum2 = accumulate(A.begin() + K, A.end(), 0);
    cout << sum2 - sum1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}