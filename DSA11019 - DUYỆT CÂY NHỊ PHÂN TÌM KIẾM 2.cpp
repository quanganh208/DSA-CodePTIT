#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *constructBST(int arr[], int start, int end)
{
    if (start > end)
        return nullptr;
    Node *root = new Node;
    root->data = arr[start];
    root->left = nullptr;
    root->right = nullptr;
    int i;
    for (i = start + 1; i <= end; i++)
        if (arr[i] > root->data)
            break;
    root->left = constructBST(arr, start + 1, i - 1);
    root->right = constructBST(arr, i, end);
    return root;
}
void postOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
void solve()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    Node *root = constructBST(A, 0, N - 1);
    postOrderTraversal(root);
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