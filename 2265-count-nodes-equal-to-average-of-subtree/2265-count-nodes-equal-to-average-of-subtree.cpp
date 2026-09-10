/*
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
    pair<int, int> solve(TreeNode* root, int& ans){
        if(!root) return {0, 0};
        pair<int, int> lft = solve(root->left, ans);
        pair<int, int> rgt = solve(root->right, ans);
        int sum = lft.first + rgt.first + root->val;
        int cnt = lft.second + rgt.second + 1;
        if(sum/cnt == root->val) ans++;
        return {sum, cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};