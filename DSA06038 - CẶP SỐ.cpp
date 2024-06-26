#include <bits/stdc++.h>
using namespace std;
int Merge(int a[], int l, int m, int r)
{
    vector<int> v1(a + l, a + m + 1);
    vector<int> v2(a + m + 1, a + r + 1);
    int i = 0, j = 0, cnt = 0;
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
int MergeSort(int a[], int l, int r)
{
    int ans = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        ans += MergeSort(a, l, m);
        ans += MergeSort(a, m + 1, r);
        ans += Merge(a, l, m, r);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int index = 0, even[100001] = {};
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            even[index++] = a[i];
    int res = MergeSort(even, 0, index - 1);
    a[n] = 1;
    int even_cnt = 0;
    for (int i = 0; i < n; i++)
        if ((a[i] % 2 == 0) and (a[i + 1] % 2 == 0))
            even_cnt++;
        else if ((a[i] % 2 == 0) and (a[i + 1] % 2 == 1))
        {
            res -= MergeSort(a, i - even_cnt, i);
            even_cnt = 0;
        }
    cout << res;
    return 0;
}