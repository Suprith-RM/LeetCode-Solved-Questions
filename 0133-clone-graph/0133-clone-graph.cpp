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
        if(!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(auto& it: curr->neighbors){
                if(!mp.count(it)){
                    mp[it] = new Node(it->val); 
                    q.push(it);
                }
                mp[curr]->neighbors.push_back(mp[it]);
            }
        }
        return mp[node];
    }
};