/* Binary Tree Node Structure
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
    int ans;
    int prev;
    bool hasPrev;

    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        if (hasPrev)
            ans = min(ans, root->data - prev);

        prev = root->data;
        hasPrev = true;

        inorder(root->right);
    }

    int absDiff(Node* root) {
        ans = INT_MAX;
        prev = 0;
        hasPrev = false;

        inorder(root);

        return ans;
    }
};