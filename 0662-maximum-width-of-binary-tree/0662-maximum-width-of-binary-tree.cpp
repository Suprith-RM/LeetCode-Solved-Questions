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
public:
    int widthOfBinaryTree(TreeNode* root) {
        int lvl = 0, mx_width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        while(!q.empty()){
            int sz = q.size();
            unsigned long long strt = q.front().second;
            unsigned long long end = q.back().second;
            mx_width = max(mx_width, (int)(end - strt + 1));
            for(int i = 0; i < sz; ++i){
                TreeNode* curr = q.front().first;
                unsigned long long x = q.front().second;
                q.pop();
                if(curr->left) q.push({curr->left, 2*(x - strt) + 1});
                if(curr->right) q.push({curr->right, 2*(x - strt) + 2});
            }
        }
        return mx_width;
    }
};