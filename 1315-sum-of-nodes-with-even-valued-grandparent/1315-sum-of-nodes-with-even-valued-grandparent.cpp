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
    int dfs(TreeNode* root, TreeNode* par, TreeNode* grandPar){
        if(!root) return 0;
        int lft = dfs(root->left, root, par);
        int rgt = dfs(root->right, root, par);
        int curr_sum = 0;
        if(grandPar && grandPar->val % 2 == 0){
            curr_sum = root->val; 
        }
        return (lft + rgt + curr_sum);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};