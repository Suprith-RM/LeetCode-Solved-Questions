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
    int search(vector<int>& inorder, int x, int lft, int rgt) {
        for (int i = lft; i <= rgt; ++i) {
            if (inorder[i] == x)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        if (left > right)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder, preorder[preIdx], left, right);
        preIdx++;
        root->left = build(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = build(preorder, inorder, preIdx, inIdx + 1, right);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0, left = 0, right = preorder.size() - 1;
        TreeNode* root = build(preorder, inorder, preIdx, left, right);
        return root;
    }
};