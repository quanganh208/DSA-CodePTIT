#include <bits/stdc++.h>
using namespace std;
long long Merge(long long a[], long long l, long long m, long long r)
{
    vector<long long> v1(a + l, a + m + 1);
    vector<long long> v2(a + m + 1, a + r + 1);
    long long i = 0, j = 0, cnt = 0;
    while (i < v1.size() and j < v2.size())
        if (v1[i] <= v2[j])
        {
            a[l] = v1[i];
            l++;
            i++;
        }
        else
        {
            cnt += v1.size() - i;
            a[l] = v2[j];
            l++;
            j++;
        }
    while (i < v1.size())
    {
        a[l] = v1[i];
        l++;
        i++;
    }
    while (j < v2.size())
    {
        a[l] = v2[j];
        l++;
        j++;
    }
    return cnt;
}
long long MergeSort(long long a[], long long l, long long r)
{
    long long ans = 0;
    if (l < r)
    {
        long long m = (l + r) / 2;
        ans += MergeSort(a, l, m);
        ans += MergeSort(a, m + 1, r);
        ans += Merge(a, l, m, r);
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << MergeSort(a, 0, n - 1) << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}