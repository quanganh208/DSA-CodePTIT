#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
        cout << "Buoc " << i + 1 << ": ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}