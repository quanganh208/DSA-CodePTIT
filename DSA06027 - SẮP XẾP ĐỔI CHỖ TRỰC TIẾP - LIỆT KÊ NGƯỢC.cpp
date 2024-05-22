#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    stack<vector<int>> st;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
        st.push(a);
    }
    while (!st.empty())
    {
        cout << "Buoc " << st.size() << ": ";
        for (auto i : st.top())
            cout << i << " ";
        cout << endl;
        st.pop();
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}