#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    bool haveSwap = false;
    for (int i = 0; i < n - 1; i++)
    {
        haveSwap = false;
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                haveSwap = true;
            }
        if (!haveSwap)
            break;
        cout << "Buoc " << i + 1 << ": ";
        for (auto &i : a)
            cout << i << " ";
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}