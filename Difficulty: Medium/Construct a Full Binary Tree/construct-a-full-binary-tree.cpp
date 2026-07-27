/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    unordered_map<int, int> pos;
    int preIndex = 0;
    int n;

    Node* build(vector<int>& pre, int low, int high) {
        if (preIndex >= n || low > high)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);

        if (low == high || preIndex >= n)
            return root;

        int idx = pos[pre[preIndex]];

        root->left = build(pre, idx, high);

        root->right = build(pre, low + 1, idx - 1);

        return root;
    }

    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        n = pre.size();

        for (int i = 0; i < n; i++)
            pos[preMirror[i]] = i;

        preIndex = 0;
        return build(pre, 0, n - 1);
    }
};