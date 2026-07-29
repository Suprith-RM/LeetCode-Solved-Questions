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
    int maxSum = INT_MIN;
    int dfs(TreeNode* root) {
    if (!root) return 0;
    int lft = max(0, dfs(root->left));
    int rgt = max(0, dfs(root->right));
    maxSum = max(maxSum, lft + rgt + root->val);
    return root->val + max(lft, rgt);
}
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};