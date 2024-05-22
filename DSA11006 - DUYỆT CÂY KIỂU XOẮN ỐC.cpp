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
void spiralOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *curr = s1.top();
            s1.pop();
            cout << curr->data << " ";
            if (curr->right)
                s2.push(curr->right);
            if (curr->left)
                s2.push(curr->left);
        }
        while (!s2.empty())
        {
            Node *curr = s2.top();
            s2.pop();
            cout << curr->data << " ";
            if (curr->left)
                s1.push(curr->left);
            if (curr->right)
                s1.push(curr->right);
        }
    }
}
void solve()
{
    Node *root = buildBinaryTree();
    spiralOrderTraversal(root);
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