/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root, int val, int depth, int curr) {
        if (!root)
            return;

        if (curr == depth - 1) {
            TreeNode* lft = new TreeNode(val);
            TreeNode* rgt = new TreeNode(val);

            lft->left = root->left;
            rgt->right = root->right;

            root->left = lft;
            root->right = rgt;

            return;
        }
        dfs(root->left, val, depth, curr + 1);
        dfs(root->right, val, depth, curr + 1);
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root, val, depth, 1);
        return root;
    }
};