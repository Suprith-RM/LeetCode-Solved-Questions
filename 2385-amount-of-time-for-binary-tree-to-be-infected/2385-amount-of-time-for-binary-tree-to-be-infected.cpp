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
    void build(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
    if (!root) return;

    if (root->left) {
        graph[root].push_back(root->left);
        graph[root->left].push_back(root);
        build(root->left, graph);
    }

    if (root->right) {
        graph[root].push_back(root->right);
        graph[root->right].push_back(root);
        build(root->right, graph);
    }
}
TreeNode* findNode(TreeNode* root, int target) {
        if (!root) return nullptr;
        if (root->val == target) return root;

        TreeNode* left = findNode(root->left, target);
        if (left) return left;

        return findNode(root->right, target);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        build(root, graph);
        unordered_set<TreeNode*> st;
        int time = 0;
        TreeNode* strt = findNode(root, start);
        queue<pair<TreeNode*, int>> q;
        q.push({strt, 0});
        int tm = 0;
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int temp_time = q.front().second;
            tm = max(tm, temp_time);
            q.pop();
            st.insert(temp);
            for(auto it: graph[temp]){
                if(st.find(it) == st.end()){
                    q.push({it, temp_time + 1});
                }
            }
        }
        return tm;
    }
};