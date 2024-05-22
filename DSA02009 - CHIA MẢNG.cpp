#include <bits/stdc++.h>
using namespace std;
bool partition(vector<int> &A, int index, vector<int> &subsetSum, int targetSum)
{
    if (index == A.size())
    {
        for (int i = 0; i < subsetSum.size(); i++)
            if (subsetSum[i] != targetSum)
                return false;
        return true;
    }
    for (int i = 0; i < subsetSum.size(); i++)
    {
        if (subsetSum[i] + A[index] <= targetSum)
        {
            subsetSum[i] += A[index];
            if (partition(A, index + 1, subsetSum, targetSum))
                return true;
            subsetSum[i] -= A[index];
        }
    }
    return false;
}
void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % K != 0)
    {
        cout << 0 << endl;
        return;
    }
    int targetSum = sum / K;
    vector<int> subsetSum(K, 0);
    if (!partition(A, 0, subsetSum, targetSum))
    {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}