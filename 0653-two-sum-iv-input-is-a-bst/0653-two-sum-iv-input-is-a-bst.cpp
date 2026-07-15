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
    bool inorder(TreeNode* root, int k, unordered_map<int, int>& mp){
        if(!root) return false;
        if(inorder(root->left, k, mp)) return true;
        int rem = k - root->val;
        if(mp.count(rem)){
            return true;
        }
        mp[root->val];
        if(inorder(root->right, k, mp)) return true;;
        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        return inorder(root, k, mp);
    }
};