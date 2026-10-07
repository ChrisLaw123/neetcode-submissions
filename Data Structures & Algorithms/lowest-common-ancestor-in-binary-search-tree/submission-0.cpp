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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            //if the root is between the p and q values, return root
            if ((root->val >= p->val && root->val <= q->val) || (root->val >= q->val && root->val <= p->val)) {
                return root;
            } else if (root->val > p->val && root->val > q->val) {
                //if the root is greater than both p and q go down the left side
                root = root->left;
            } else {
                //go down the right side
                root = root->right;
            }
        }
        return root;
    }
};
