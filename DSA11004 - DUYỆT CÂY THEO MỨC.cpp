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
        return root;
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
        if (root == nullptr)
            root = createNode(parentData);
        insertNode(root, parentData, data, childType);
    }
    return root;
}
void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}
void solve()
{
    Node *root = buildBinaryTree();
    levelOrderTraversal(root);
    cout << endl;
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