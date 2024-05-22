#include <bits/stdc++.h>
using namespace std;
vector<long long> intersect(vector<long long> v1, vector<long long> v2)
{
    vector<long long> v;
    int i = 0, j = 0;
    while (i < v1.size() and j < v2.size())
        if (v1[i] == v2[j])
        {
            v.push_back(v1[i]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j])
            i++;
        else
            j++;
    return v;
}
void solve()
{
    int N1, N2, N3;
    cin >> N1 >> N2 >> N3;
    vector<long long> v1(N1), v2(N2), v3(N3);
    for (auto &i : v1)
        cin >> i;
    for (auto &i : v2)
        cin >> i;
    for (auto &i : v3)
        cin >> i;
    vector<long long> v = intersect(intersect(v1, v2), v3);
    if (v.empty())
        cout << -1;
    else
        for (auto i : v)
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