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