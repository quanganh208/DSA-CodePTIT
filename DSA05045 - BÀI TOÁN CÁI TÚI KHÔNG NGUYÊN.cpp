#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    for (auto &item : items)
        if (W >= item.weight)
        {
            W -= item.weight;
            totalValue += item.value;
        }
        else
        {
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    return totalValue;
}
void solve()
{
    int n, W;
    cin >> n >> W;
    vector<Item> items;
    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }
    cout << fixed << setprecision(2) << fractionalKnapsack(W, items) << endl;
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