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
    int sum = 0;
    int height(TreeNode* root){
        if(!root) return 0;
        int lft = height(root->left);
        int rgt = height(root->right);
        return 1 + max(lft, rgt);
    }
    void dfs(TreeNode* root, int hgt, int depth){
        if(!root || depth > hgt) return;
        dfs(root->left, hgt, depth + 1);
        dfs(root->right, hgt, depth + 1);
        if(depth == hgt) sum += root->val;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int hgt = height(root);
        dfs(root, hgt, 1);
        return sum;
    }
};