#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        int x;
        while (ss >> x)
        {
            a[i][x] = 1;
            a[x][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i][j])
                cout << i << " " << j << endl;
}
int main()
{
    solve();
    return 0;
}