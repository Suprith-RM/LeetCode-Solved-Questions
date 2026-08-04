/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& graph){
        if(!root) return;
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        dfs(root->left, graph);
        dfs(root->right, graph);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph;
        dfs(root, graph);
        vector<int> ans;
        queue<pair<int, pair<int, int>>> q;
        q.push({-1, {target->val, 0}});
        while(!q.empty()){
            int par = q.front().first;
            int curr = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();
            if(dist == k){
                ans.push_back(curr);
                continue;
            } 
            for(auto& neighbour: graph[curr]){
                if(neighbour == par) continue;
                q.push({curr, {neighbour, dist+1}});
            }
        }
        return ans;
    }
};