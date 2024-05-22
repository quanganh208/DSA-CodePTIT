#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *buildTree(vector<int> &inorder, vector<int> &levelorder)
{
    if (inorder.empty() || levelorder.empty())
        return nullptr;
    int rootData = levelorder[0];
    Node *root = new Node();
    root->data = rootData;
    root->left = nullptr;
    root->right = nullptr;
    int rootIndex = -1;
    for (int i = 0; i < inorder.size(); i++)
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
    vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
    vector<int> leftLevelorder;
    vector<int> rightLevelorder;
    for (int i = 1; i < levelorder.size(); i++)
        if (find(leftInorder.begin(), leftInorder.end(), levelorder[i]) != leftInorder.end())
            leftLevelorder.push_back(levelorder[i]);
        else
            rightLevelorder.push_back(levelorder[i]);
    root->left = buildTree(leftInorder, leftLevelorder);
    root->right = buildTree(rightInorder, rightLevelorder);
    return root;
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
    vector<int> levelorder(n);
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> levelorder[i];
    Node *root = buildTree(inorder, levelorder);
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