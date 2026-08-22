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
    bool isLeaf(TreeNode* root){
        return (!root->left && !root->right);
    }
    void dfs(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>> &ans){
        if(isLeaf(root) && targetSum == 0){
            ans.push_back(temp);
            return;
        }
        if(root->left){
            temp.push_back(root->left->val);
            dfs(root->left, targetSum - root->left->val, temp, ans);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->right->val);
            dfs(root->right, targetSum - root->right->val, temp, ans);
            temp.pop_back();
        }
        
        

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> temp = {root->val};
        dfs(root, targetSum - root->val, temp, ans);
        return ans;
    }
};