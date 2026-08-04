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
    int total_sum = 0;
    long long mx_prod = 0;
    void dfs_sum(TreeNode* root) {
        if (!root)
            return;
        dfs_sum(root->left);
        dfs_sum(root->right);
        total_sum += root->val;
    }
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        mx_prod = max(mx_prod, (1LL * (l) * (total_sum - l)));
        mx_prod = max(mx_prod, (1LL * (r) * (total_sum - r)));
        return l + r + root->val;
    }

public:
    int maxProduct(TreeNode* root) {
        dfs_sum(root);
        dfs(root);
        const int MOD = 1e9 + 7;
        return mx_prod % MOD;
    }
};