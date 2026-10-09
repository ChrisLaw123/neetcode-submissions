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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;

        queue<TreeNode*> q;
        q.push(root);
        bool res{};
        //bfs until we find the matching node, then cont bfs on both nodes checking for equality
        while (!q.empty()) {
            int size = q.size();
            for (int i{}; i < size; i++) {
                if (q.front()->val == subRoot->val) {
                    //perform dfs on the two
                    res = max(res, dfs(q.front(), subRoot)); 
                }
                if (q.front()->left  != nullptr) q.push(q.front()->left);
                if (q.front()->right != nullptr) q.push(q.front()->right);
                q.pop();
            }

        }

        return res;
    }

    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr && subRoot != nullptr) return false;
        if (root != nullptr && subRoot == nullptr) return false;
        if (root->val != subRoot->val) return false;

        return min(dfs(root->left, subRoot->left), dfs(root->right, subRoot->right));
    }
};
