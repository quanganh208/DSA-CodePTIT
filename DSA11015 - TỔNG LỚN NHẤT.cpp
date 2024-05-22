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
int maxSum(Node *root, int &res)
{
    if (root == nullptr)
        return 0;
    int leftSum = maxSum(root->left, res);
    int rightSum = maxSum(root->right, res);
    if (root->left == nullptr && root->right == nullptr)
        return root->data;
    if (root->left == nullptr)
        return root->data + rightSum;
    if (root->right == nullptr)
        return root->data + leftSum;
    if (root->left != nullptr && root->right != nullptr)
    {
        res = max(res, leftSum + rightSum + root->data);
        return max(leftSum, rightSum) + root->data;
    }
}
void solve()
{
    Node *root = buildBinaryTree();
    int res = INT_MIN;
    maxSum(root, res);
    cout << res << endl;
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