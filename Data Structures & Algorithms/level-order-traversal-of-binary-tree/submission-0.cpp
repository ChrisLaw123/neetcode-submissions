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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            vector<int> row;
            for (int i{}; i < size; i++) {
                //for every element in q, add to vector then pop

                row.push_back(q.front()->val);
                if (q.front()->left  != nullptr) q.push(q.front()->left);
                if (q.front()->right != nullptr) q.push(q.front()->right);
                q.pop();
            }

            res.push_back(row);
        }

        return res;

    }
};
