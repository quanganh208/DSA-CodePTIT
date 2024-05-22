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
bool checkLeafLevel(Node *root, int level)
{
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return level == 0;
    return checkLeafLevel(root->left, level - 1) && checkLeafLevel(root->right, level - 1);
}
bool checkSameLeafLevel(Node *root)
{
    if (root == nullptr)
        return true;
    int level = -1;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        level++;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }
    return checkLeafLevel(root, level);
}
void solve()
{
    Node *root = buildBinaryTree();
    cout << checkSameLeafLevel(root) << endl;
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