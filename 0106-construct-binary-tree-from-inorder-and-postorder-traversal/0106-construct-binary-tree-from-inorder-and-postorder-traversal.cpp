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
    int search(vector<int>& inorder, int x, int lft, int rgt){
        for(int i = lft; i <= rgt; ++i){
            if(inorder[i] == x) return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& postIdx, int left, int right){
        if(left > right) return nullptr;
        TreeNode* root = new TreeNode(postorder[postIdx]);
        int inIdx = search(inorder, postorder[postIdx], left, right);
        postIdx--;
        root->right = build(inorder, postorder, postIdx, inIdx + 1, right);
        root->left = build(inorder, postorder, postIdx, left, inIdx - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIdx = postorder.size() - 1, left = 0, right = postIdx;
        TreeNode* root = build(inorder, postorder, postIdx, left, right);
        return root;
    }
};