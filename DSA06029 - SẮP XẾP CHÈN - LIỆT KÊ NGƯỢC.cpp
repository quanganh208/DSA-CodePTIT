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
        vector<int> tmp;
        for (int j = 0; j < i + 1; j++)
            tmp.push_back(a[j]);
        st.push(tmp);
    }
    while (!st.empty())
    {
        cout << "Buoc " << st.size() - 1 << ": ";
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