#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), left(n), right(n);
    for (auto &x : a)
        cin >> x;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and a[st.top()] >= a[i])
            st.pop();
        left[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and a[st.top()] >= a[i])
            st.pop();
        right[i] = st.empty() ? n - 1 : st.top() - 1;
        st.push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, 1LL * a[i] * (right[i] - left[i] + 1));
    cout << ans << endl;
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