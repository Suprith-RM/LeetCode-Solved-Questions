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
    vector<int> arr;
    int idx = 0;
    void traverse_1(TreeNode* root){
        if(!root) return;
        traverse_1(root->left);
        arr.push_back(root->val);
        traverse_1(root->right);
    }
    void traverse_2(TreeNode* root){
        if(!root) return;
        traverse_2(root->left);
        root->val = arr[idx++];
        traverse_2(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        traverse_1(root);
        sort(arr.begin(), arr.end());
        traverse_2(root);
    }
};