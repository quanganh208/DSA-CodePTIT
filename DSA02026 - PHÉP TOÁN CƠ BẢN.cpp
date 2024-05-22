#include <bits/stdc++.h>
using namespace std;
string str;
bool isCorrectFlag;
bool isCorrect()
{
    int x = stoi(str.substr(0, 2));
    int y = stoi(str.substr(5, 2));
    int z = stoi(str.substr(10, 2));
    if (x < 10 or y < 10 or z < 10)
        return false;
    if (str[3] == '+')
        return (x + y == z);
    else
        return (x - y == z);
}
void Try(int i)
{
    if (isCorrectFlag)
        return;
    if (i == str.length())
    {
        if (isCorrect())
        {
            isCorrectFlag = true;
            cout << str << endl;
        }
        return;
    }
    if (str[i] == '?')
    {
        if (i == 3)
        {
            str[i] = '+';
            Try(i + 1);
            str[i] = '-';
            Try(i + 1);
        }
        else
            for (char c = '0'; c <= '9'; c++)
            {
                str[i] = c;
                Try(i + 1);
            }
        str[i] = '?';
    }
    else
        Try(i + 1);
}
void solve()
{
    getline(cin >> ws, str);
    isCorrectFlag = false;
    if (str.find("*") != string::npos or str.find("/") != string::npos)
    {
        cout << "WRONG PROBLEM!" << endl;
        return;
    }
    Try(0);
    if (!isCorrectFlag)
        cout << "WRONG PROBLEM!" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}