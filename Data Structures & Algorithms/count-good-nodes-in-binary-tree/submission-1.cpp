/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int goodNodes{};

        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()) {

            for (int i = q.size() - 1; i >= 0; i--) {
                auto [node, max] = q.front();
                q.pop();

                if (node->val >= max) {
                    goodNodes++;
                }

                int newMax = std::max(node->val, max);
                if (node->left != nullptr) {
                    q.push({node->left, newMax});
                }
                if (node->right != nullptr) {
                    q.push({node->right, newMax});
                }
            }
        }
        return goodNodes;
    }
};
