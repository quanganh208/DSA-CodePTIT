#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A.begin(), A.end(), greater<int>());
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 3 == 0)
        for (int i = 0; i < n; i++)
            cout << A[i];
    else
    {
        int smallestDigit = 10;
        for (int i = 0; i < n; i++)
            if (A[i] % 3 == sum % 3)
                smallestDigit = min(smallestDigit, A[i]);
        for (int i = 0; i < n; i++)
            if (A[i] == smallestDigit)
            {
                A.erase(A.begin() + i);
                break;
            }
        int newSum = accumulate(A.begin(), A.end(), 0);
        if (newSum % 3 == 0)
            for (int i = 0; i < A.size(); i++)
                cout << A[i];
        else
            cout << -1;
    }
    cout << endl;
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