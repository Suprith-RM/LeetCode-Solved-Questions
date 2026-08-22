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
class FindElements {
    void dfs(TreeNode*& root){
        if(root->left){
            root->left->val = (root->val * 2) + 1;
            st.insert(root->left->val);
            dfs(root->left);
        }
        if(root->right){
            root->right->val = (root->val * 2) + 2;
            st.insert(root->right->val);
            dfs(root->right);
        }
    }
public:
unordered_set<int> st;

    FindElements(TreeNode* root) {
        st.insert(0);
        root->val = 0;
        dfs(root);
    }
    
    bool find(int target) {
        if(st.count(target)) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */