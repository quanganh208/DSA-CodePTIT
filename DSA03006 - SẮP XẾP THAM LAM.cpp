#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A)
        cin >> x;
    vector<int> B(A);
    sort(B.begin(), B.end());
    for (int i = 0; i < N / 2; i++)
        if (B[i] != A[i] and B[i] != A[N - i - 1])
        {
            cout << "No" << endl;
            return;
        }
    cout << "Yes" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}