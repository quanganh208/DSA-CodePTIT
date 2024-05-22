#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), nextGreater(n), rightSmaller(n);
    for (auto &x : a)
        cin >> x;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and a[st.top()] <= a[i])
            st.pop();
        if (st.empty())
            nextGreater[i] = -1;
        else
            nextGreater[i] = st.top();
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and st.top() >= a[i])
            st.pop();
        if (st.empty())
            rightSmaller[i] = -1;
        else
            rightSmaller[i] = st.top();
        st.push(a[i]);
    }
    for (int i = 0; i < n; i++)
        if (nextGreater[i] == -1)
            cout << -1 << " ";
        else
            cout << rightSmaller[nextGreater[i]] << " ";
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