/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        vector<int> costs;
        queue<pair<Node*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (!node->left && !node->right) {
                costs.push_back(level);
            }

            if (node->left)
                q.push({node->left, level + 1});

            if (node->right)
                q.push({node->right, level + 1});
        }

        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {
            if (k < cost)
                break;

            k -= cost;
            count++;
        }

        return count;
    }
};