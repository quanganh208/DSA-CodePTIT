#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10005;
const int MAX_MASK = 16;
const long long NEG_INF = -1e18;
void solve()
{
    int n;
    cin >> n;
    long long grid[4][MAX_N];
    long long maxScore = NEG_INF;
    // Đọc dữ liệu đầu vào và tìm điểm lớn nhất
    for (int i = 0; i < 4; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
            maxScore = max(maxScore, grid[i][j]);
        }
    // Nếu điểm lớn nhất âm hoặc bằng 0, in ra và kết thúc
    if (maxScore <= 0)
    {
        cout << maxScore << endl;
        return;
    }
    // Tạo bitset cho các mask hợp lệ
    bitset<MAX_MASK> validMask;
    for (int i = 0; i < MAX_MASK; i++)
    {
        bool isValid = true;
        for (int j = 0; j < 4; j++)
            if ((i >> j) & 1 and (i >> (j + 1)) & 1)
            {
                isValid = false;
                break;
            }
        validMask[i] = isValid;
    }
    // Tính toán và lưu trữ điểm tối đa có thể đạt được
    long long dp[MAX_N][MAX_MASK];
    for (int i = 1; i <= n; i++)
        for (int mask = 0; mask < MAX_MASK; mask++)
        {
            dp[i][mask] = NEG_INF;
            if (validMask[mask])
            {
                int sum = 0;
                for (int z = 0; z < 4; z++)
                    sum += grid[z][i] * ((mask >> z) & 1);
                for (int prevMask = 0; prevMask < MAX_MASK; prevMask++)
                    if (validMask[prevMask] and !(mask & prevMask))
                        dp[i][mask] = max(dp[i][mask], dp[i - 1][prevMask] + sum);
            }
            maxScore = max(maxScore, dp[i][mask]);
        }
    cout << maxScore << endl;
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