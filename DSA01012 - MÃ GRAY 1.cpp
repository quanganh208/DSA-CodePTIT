#include <bits/stdc++.h>
using namespace std;
void generateGray(int n)
{
    vector<string> arr = {"0", "1"};
    for (int i = 2; i < pow(2, n); i *= 2)
    {
        for (int j = i - 1; j >= 0; j--)
            arr.push_back(arr[j]);
        for (int j = 0; j < i; j++)
            arr[j] = "0" + arr[j];
        for (int j = i; j < 2 * i; j++)
            arr[j] = "1" + arr[j];
    }
    for (auto i : arr)
        cout << i << " ";
}
void solve()
{
    int n;
    cin >> n;
    generateGray(n);
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}