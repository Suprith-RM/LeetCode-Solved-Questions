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
    int check(TreeNode* root) {
        if (!root)
            return 0;
        int lft = check(root->left);
        if (lft == -101)
            return lft;
        int rgt = check(root->right);
        if (rgt == -101)
            return rgt;
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        if (root->val != (lft + rgt))
            return -101;
        return lft + rgt + root->val;
    }

public:
    bool checkTree(TreeNode* root) {
        return (check(root) == -101) ? false : true;
    }
};