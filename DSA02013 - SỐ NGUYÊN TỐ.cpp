#include <bits/stdc++.h>
using namespace std;
int n, p, s;
vector<int> a, x;
vector<vector<int>> res;
int current = 0;
void Eratosthenes()
{
    vector<bool> prime(201, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 200; i++)
        if (prime[i])
        {
            a.push_back(i);
            for (int j = i * i; j <= 200; j += i)
                prime[j] = false;
        }
}
void Try(int i)
{
    for (int j = i; j < a.size(); j++)
    {
        current += a[j];
        x.push_back(a[j]);
        if (current == s and x.size() == n)
            res.push_back(x);
        else if (current < s)
            Try(j + 1);
        current -= a[j];
        x.pop_back();
    }
}
void solve()
{
    cin >> n >> p >> s;
    current = 0;
    x.clear();
    res.clear();
    int idx = 0;
    while (a[idx] <= p)
        idx++;
    Try(idx);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    Eratosthenes();
    while (t--)
        solve();
    return 0;
}