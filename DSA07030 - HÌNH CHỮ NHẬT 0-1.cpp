#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left(n), right(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            right[st.top()] = i;
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    int maxArea = 0;
    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
    return maxArea;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    int maxArea = 0;
    vector<int> heights(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 0)
                heights[j] = 0;
            else
                heights[j]++;
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    cout << maxArea << endl;
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