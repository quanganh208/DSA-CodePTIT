#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] <= a[i])
            st.pop();
        if (st.empty())
            cout << i + 1 << " ";
        else
            cout << i - st.top() << " ";
        st.push(i);
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}