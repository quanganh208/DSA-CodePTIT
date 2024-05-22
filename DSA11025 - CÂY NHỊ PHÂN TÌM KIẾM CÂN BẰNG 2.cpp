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
Node *buildBinaryTree(Node *&root, vector<int> &a, int left, int right)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        root = createNode(a[mid]);
        root->left = buildBinaryTree(root->left, a, left, mid - 1);
        root->right = buildBinaryTree(root->right, a, mid + 1, right);
    }
    return root;
}
void preOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    Node *root = nullptr;
    root = buildBinaryTree(root, a, 0, n - 1);
    preOrderTraversal(root);
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