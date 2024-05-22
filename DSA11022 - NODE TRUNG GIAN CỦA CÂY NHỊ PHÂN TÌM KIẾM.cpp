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
int countIntermediateNodes(Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return 0;
    return 1 + countIntermediateNodes(root->left) + countIntermediateNodes(root->right);
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
    cout << countIntermediateNodes(root) << endl;
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