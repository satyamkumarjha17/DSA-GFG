/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (!root1 || !root2)
            return root1 == root2;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            if (n1 != n2)
                return false;

            unordered_map<int, int> freq;

            for (int i = 0; i < n1; i++) {
                Node* node = q1.front();
                q1.pop();

                freq[node->data]++;

                if (node->left)
                    q1.push(node->left);

                if (node->right)
                    q1.push(node->right);
            }

            for (int i = 0; i < n2; i++) {
                Node* node = q2.front();
                q2.pop();

                if (--freq[node->data] < 0)
                    return false;

                if (node->left)
                    q2.push(node->left);

                if (node->right)
                    q2.push(node->right);
            }

            for (auto& [value, count] : freq) {
                if (count != 0)
                    return false;
            }
        }

        return q1.empty() && q2.empty();
    }
};
