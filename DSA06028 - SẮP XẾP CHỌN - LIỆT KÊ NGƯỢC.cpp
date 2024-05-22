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
        int min_i = i;
        for (int j = i + 1; j < n; j++)
            if (a[min_i] > a[j])
                min_i = j;
        swap(a[min_i], a[i]);
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
    solve();
    return 0;
}