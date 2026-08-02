/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(node->neighbors.empty()) return new Node(node->val);
        unordered_map<int, Node*> mp;
        unordered_set<int> vis;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            vis.insert(curr->val);
            if(mp.find(curr->val) == mp.end()){
                mp[curr->val] = new Node(curr->val);
            }
            for(auto& it: curr->neighbors){
                if(mp.find(it->val) == mp.end()){
                    mp[it->val] = new Node(it->val);
                }
                if(vis.find(it->val) == vis.end()){
                    mp[curr->val]->neighbors.push_back(mp[it->val]); 
                    mp[it->val]->neighbors.push_back(mp[curr->val]); 
                    q.push(it);
                }
            }
        }
        return mp[node->val];
    }
};