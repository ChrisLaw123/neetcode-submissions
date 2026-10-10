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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;

        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            
            //extract all left most nodes
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            //push the node, node above onto res, then repeat with right
            curr = s.top();
            res.push_back(curr->val);
            s.pop();
            curr = curr->right;
        }

        return res[k-1];
    }
};
