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
    void dfs(TreeNode*& root, unordered_map<int, int>& mp, vector<TreeNode*>& ans){
        if(!root) return;

        dfs(root->left, mp, ans);
        dfs(root->right, mp, ans);

        if(mp.count(root->val)){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            root = nullptr;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, int> mp;
        for(int num: to_delete){
            mp[num]++;
        }
        vector<TreeNode*> ans;
        dfs(root, mp, ans);
        if(root) ans.push_back(root);
        return ans;
    }
};