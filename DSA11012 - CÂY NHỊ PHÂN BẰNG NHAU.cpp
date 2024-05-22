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
    if (newNode)
    {
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
    }
    return newNode;
}
Node *insertNode(Node *root, int parentData, int data, char childType)
{
    if (root == nullptr)
    {
        root = createNode(parentData);
        if (childType == 'L')
            root->left = createNode(data);
        else if (childType == 'R')
            root->right = createNode(data);
        return root;
    }
    if (root->data == parentData)
    {
        if (childType == 'L')
            root->left = createNode(data);
        else if (childType == 'R')
            root->right = createNode(data);
    }
    else
    {
        insertNode(root->left, parentData, data, childType);
        insertNode(root->right, parentData, data, childType);
    }
    return root;
}
Node *buildBinaryTree()
{
    int n;
    cin >> n;
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int parentData, data;
        char childType;
        cin >> parentData >> data >> childType;
        root = insertNode(root, parentData, data, childType);
    }
    return root;
}
bool isSameTree(Node *p, Node *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
    if (p->data != q->data)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
void solve()
{
    Node *root1 = buildBinaryTree();
    Node *root2 = buildBinaryTree();
    cout << isSameTree(root1, root2) << endl;
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