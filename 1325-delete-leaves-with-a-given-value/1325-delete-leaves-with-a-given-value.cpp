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
    void remove(TreeNode* root, int target, bool& rem){
        if(!root) return;
        remove(root->left, target, rem);
        if(rem){
            root->left = nullptr;
            rem = false;
        }
        remove(root->right, target, rem);
        if(rem){
            root->right = nullptr;
            rem = false;
        }
        if(isLeaf(root) && root->val == target){
            rem = true;
        }
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool rem = false;
        remove(root, target, rem);
        if(rem) return nullptr;
        return root;
    }
};