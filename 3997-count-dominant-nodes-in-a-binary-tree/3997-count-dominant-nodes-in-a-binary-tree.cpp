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
    int helper(TreeNode* root, int& ans){
        if(root == nullptr) return -1;
        int lft_max = helper(root->left, ans);
        int rgt_max = helper(root->right, ans);
        if(root->val >= lft_max && root->val >= rgt_max) ans++;
        return max(root->val, max(lft_max, rgt_max));
    }
public:
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};