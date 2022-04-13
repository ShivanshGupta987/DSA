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
// TC : O(N)
// N -> NO. OF NODES IN THE TREE
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     
            if(root==NULL)return {};
            deque<TreeNode*>dq;
            dq.push_front(root);
            bool zig = true;
            
            vector<vector<int>>res;
            vector<int>vec;
            
            while(!dq.empty())
            {
                 for(int i=dq.size()-1; i>=0; i--)
                 {
                    if(zig)
                    {
                            TreeNode* temp = dq.front();
                            dq.pop_front();
                            vec.push_back(temp->val);
                            if(temp->left) dq.push_back(temp->left);
                            if(temp->right) dq.push_back(temp->right);
                            
                    }  
                    else 
                    {
                            TreeNode* temp = dq.back();
                            dq.pop_back();
                            vec.push_back(temp->val);
                            if(temp->right) dq.push_front(temp->right);
                            if(temp->left) dq.push_front(temp->left);                   
                    }
                         
                 }
                    res.push_back(vec);
                    vec.clear();
                    zig = !zig;
            }
            return res;
            
    }
};