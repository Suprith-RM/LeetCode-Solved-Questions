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
    int dfs(TreeNode*& root){
        if(!root) return 0;
        int lft = dfs(root->left);
        int rgt = dfs(root->right);
        int sum = lft + rgt + root->val;
        if(sum == 0) root = nullptr;
        return sum;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};