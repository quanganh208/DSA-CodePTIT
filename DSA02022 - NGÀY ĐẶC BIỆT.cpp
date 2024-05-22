#include <bits/stdc++.h>
using namespace std;
bool isValidDate(int day, int month, int year)
{
    if (year < 2000)
        return false;
    if (month < 1 or month > 12)
        return false;
    if (day < 1 or day > 31)
        return false;
    return true;
}
void generateSpecialDates(vector<string> &result, string &date, int index)
{
    if (index == 8)
    {
        if (isValidDate(stoi(date.substr(0, 2)), stoi(date.substr(2, 2)), stoi(date.substr(4, 4))))
            result.push_back(date);
        return;
    }
    for (char c : {'0', '2'})
    {
        date[index] = c;
        generateSpecialDates(result, date, index + 1);
    }
}
int main()
{
    vector<string> specialDates;
    string date = "00000000";
    generateSpecialDates(specialDates, date, 0);
    sort(specialDates.begin(), specialDates.end());
    for (string &date : specialDates)
        cout << date.substr(0, 2) << "/" << date.substr(2, 2) << "/" << date.substr(4, 4) << endl;
    return 0;
}