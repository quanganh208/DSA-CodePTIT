#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node *insertNode(Node *root, int data)
{
    if (root == nullptr)
    {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}
int findDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}
int depthOfTree(Node *root)
{
    return findDepth(root) - 1;
}
void solve()
{
    int n;
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }
    cout << depthOfTree(root) << endl;
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