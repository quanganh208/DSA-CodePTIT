#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(const string &str, int left, int right)
{
    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string S;
    cin >> S;
    int N = S.length();
    int Q;
    cin >> Q;
    while (Q--)
    {
        char queryType;
        cin >> queryType;
        if (queryType == 'q')
        {
            int L, R;
            cin >> L >> R;
            L--, R--; // Convert to 0-based index
            if (isPalindrome(S, L, R))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (queryType == 'c')
        {
            int U, x;
            cin >> U >> x;
            U--; // Convert to 0-based index
            S[U] = x + '0'; // Convert x to a character and update the string
        }
    }
    return 0;
}