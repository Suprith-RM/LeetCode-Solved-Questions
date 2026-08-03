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
    int mx_depth = -1;
    void dfs(TreeNode* root, int depth, int& ans){
        if(!root) return;
        if(depth > mx_depth){
            ans = root->val;
            mx_depth = depth;
        }
        dfs(root->left, depth+1, ans);
        dfs(root->right, depth+1, ans);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0;
        int ans = 0;
        dfs(root, depth, ans);
        return ans;
    }
};