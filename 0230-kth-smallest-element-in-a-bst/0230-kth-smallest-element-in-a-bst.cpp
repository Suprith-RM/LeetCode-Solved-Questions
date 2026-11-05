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
    int helper(TreeNode* root, int& k){
        if(!root)
            return -1;
        int l = helper(root->left, k);
        k--;
        if(k==0){
            return root->val;
        }
        if(l != -1)
            return l;
        return helper(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k); 
    }
};