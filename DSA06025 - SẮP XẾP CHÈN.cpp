#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        cout << "Buoc " << i << ": ";
        for (int j = 0; j < i + 1; j++)
            cout << a[j] << " ";
        cout << endl;
    }
}
int main()
{
    solve();
    return 0;
}