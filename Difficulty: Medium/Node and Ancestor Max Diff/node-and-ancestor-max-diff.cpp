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
};*/

class Solution {
  public:
    int helper(Node* root, int &ans) {
        if (root == nullptr)
            return INT_MAX;

        if (root->left == nullptr && root->right == nullptr)
            return root->data;

        int leftMin = helper(root->left, ans);
        int rightMin = helper(root->right, ans);

        int descendantMin = min(leftMin, rightMin);

        ans = max(ans, root->data - descendantMin);

        return min(root->data, descendantMin);
    }

    int maxDiff(Node* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};