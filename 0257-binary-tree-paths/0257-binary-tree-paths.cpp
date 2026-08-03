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
    void dfs(TreeNode* root, string& temp, vector<string>& ans){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(temp);
            return;
        }
        if(root->left){
            temp += "->";
            temp += to_string(root->left->val);
            dfs(root->left, temp, ans);
            while(temp.back() != '>') 
                temp.pop_back();
            temp.pop_back();
            temp.pop_back();
        }
        if(root->right){
            temp += "->";
            temp += to_string(root->right->val);
            dfs(root->right, temp, ans);
            while(temp.back() != '>') 
                temp.pop_back();
            temp.pop_back();
            temp.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = to_string(root->val);
        cout << temp;
        dfs(root, temp, ans);
        return ans;
    }
};