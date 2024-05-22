#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void partition(int N, vector<int> &current_partition, vector<vector<int>> &res, int max_val)
{
    if (N == 0)
    {
        res.push_back(current_partition);
        return;
    }
    for (int i = 1; i <= min(N, max_val); i++)
    {
        current_partition.push_back(i);
        partition(N - i, current_partition, res, i);
        current_partition.pop_back();
    }
}
void print_partitions(int N)
{
    vector<int> current_partition;
    vector<vector<int>> res;
    partition(N, current_partition, res, N);
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto v : res)
    {
        cout << "(";
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << (i == v.size() - 1 ? ") " : " ");
    }
    cout << endl;
}
void solve()
{
    int n;
    cin >> n;
    print_partitions(n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}