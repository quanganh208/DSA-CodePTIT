#include <bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> a, vector<int> b)
{
    vector<int> result;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
    return result;
}
void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> a(N), b(M), c(K);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
        cin >> b[i];
    for (int i = 0; i < K; i++)
        cin >> c[i];
    vector<int> result = intersection(intersection(a, b), c);
    if (result.empty())
        cout << "NO";
    else
        for (int i : result)
            cout << i << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}