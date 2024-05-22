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
        int min_i = i;
        for (int j = i + 1; j < n; j++)
            if (a[min_i] > a[j])
                min_i = j;
        swap(a[min_i], a[i]);
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