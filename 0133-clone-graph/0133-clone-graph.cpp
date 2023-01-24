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

// TC : O(V+E)
// SC : O(N)
class Solution {
    unordered_map<int,Node*>mp;
    
    Node* dfs(Node* node){
        if(!node) return NULL;
        Node* root = new Node(node->val,{});
        mp[root->val] = root;
        for(auto &child:node->neighbors){
            if(mp.find(child->val)!=mp.end()){
                root->neighbors.push_back(mp[child->val]);
            }
            else root->neighbors.push_back(dfs(child));
        }
        return root;
        
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};