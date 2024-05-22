#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *buildTree(vector<int> &inorder, vector<int> &preorder, int inStart, int inEnd, int &preIndex)
{
    if (inStart > inEnd)
        return nullptr;
    Node *node = new Node();
    node->data = preorder[preIndex++];
    node->left = nullptr;
    node->right = nullptr;
    if (inStart == inEnd)
        return node;
    int inIndex;
    for (int i = inStart; i <= inEnd; i++)
        if (inorder[i] == node->data)
        {
            inIndex = i;
            break;
        }
    node->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);
    return node;
}
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}
void solve()
{
    int n;
    cin >> n;
    vector<int> inorder(n);
    vector<int> preorder(n);
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    int preIndex = 0;
    Node *root = buildTree(inorder, preorder, 0, n - 1, preIndex);
    postorderTraversal(root);
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