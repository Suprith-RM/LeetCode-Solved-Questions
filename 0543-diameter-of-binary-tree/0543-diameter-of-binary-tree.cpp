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
    int dia = INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int lft = dfs(root->left);
        int rgt = dfs(root->right);
        dia = max(dia, (lft + rgt));
        return 1 + max(lft, rgt);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return dia;
    }
};