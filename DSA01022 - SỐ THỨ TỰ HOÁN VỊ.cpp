#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
int findPermutationIndex(const std::vector<int> &permutation)
{
    int n = permutation.size();
    int index = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int smallerCount = 0;
        for (int j = i + 1; j < n; ++j)
            if (permutation[j] < permutation[i])
                ++smallerCount;
        index += smallerCount * factorial(n - i - 1);
    }
    return index + 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    cout << findPermutationIndex(a) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}