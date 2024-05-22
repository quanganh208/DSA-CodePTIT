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
void inorderTraversal(Node *root, vector<int> &values)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, values);
    values.push_back(root->data);
    inorderTraversal(root->right, values);
}
void assignValues(Node *root, vector<int> &values, int &index)
{
    if (root == nullptr)
        return;
    assignValues(root->left, values, index);
    root->data = values[index++];
    assignValues(root->right, values, index);
}
void convertToBinarySearchTree(Node *root)
{
    vector<int> values;
    inorderTraversal(root, values);
    sort(values.begin(), values.end());
    int index = 0;
    assignValues(root, values, index);
}
void solve()
{
    Node *root = buildBinaryTree();
    convertToBinarySearchTree(root);
    vector<int> values;
    inorderTraversal(root, values);
    for (int value : values)
        cout << value << " ";
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