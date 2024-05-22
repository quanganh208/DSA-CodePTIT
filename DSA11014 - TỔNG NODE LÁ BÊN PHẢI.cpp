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
Node *buildBinaryTree()
{
    int n;
    cin >> n;
    Node *root = nullptr;
    unordered_map<int, Node *> m;
    for (int i = 0; i < n; i++)
    {
        int parentData, data;
        char childType;
        cin >> parentData >> data >> childType;
        if (m.find(parentData) == m.end())
        {
            root = createNode(parentData);
            if (childType == 'L')
                root->left = createNode(data);
            else if (childType == 'R')
                root->right = createNode(data);
            m[data] = root->left;
            m[parentData] = root;
        }
        else
        {
            if (childType == 'L')
            {
                m[parentData]->left = createNode(data);
                m[data] = m[parentData]->left;
            }
            else if (childType == 'R')
            {
                m[parentData]->right = createNode(data);
                m[data] = m[parentData]->right;
            }
        }
    }
    return root;
}
long long sumRightLeafNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    long long sum = 0;
    if (root->right != nullptr && root->right->left == nullptr && root->right->right == nullptr)
        sum += root->right->data;
    sum += sumRightLeafNodes(root->left);
    sum += sumRightLeafNodes(root->right);
    return sum;
}
void solve()
{
    Node *root = buildBinaryTree();
    cout << sumRightLeafNodes(root) << endl;
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