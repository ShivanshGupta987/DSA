/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// TC : O(N)
// N -> NO. OF NODES 

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
            if(root==NULL)return {};
            vector<vector<int>>res;
            queue<Node*>q;
            q.push(root);
            
            vector<int>vec;
            while(!q.empty())
            {
                 for(int i=q.size()-1;i>=0;i--)
                 {
                         Node* temp = q.front();
                         q.pop();
                         vec.push_back(temp->val);
                         
                         for(auto & child : temp->children)
                         {
                                 if(child) q.push(child);
                         }
                         
                 }
                    res.push_back(vec);
                    vec.clear();
            }
            return res;
    }
};