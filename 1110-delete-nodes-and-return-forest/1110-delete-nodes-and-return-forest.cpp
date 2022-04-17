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

    vector<TreeNode*>res;

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
            set<int>s;
            for(auto x:to_delete)s.insert(x);
            dfs(root,s,true);
            return res;
    }

private: 
        TreeNode* dfs(TreeNode*  node, set<int>& s, bool is_root)
        {
                if(node == NULL) return NULL;
                bool deleted = (s.count(node->val)==1);
                
                if(is_root && !deleted) res.push_back(node);
                
                node->left = dfs(node->left,s,deleted);
                node->right = dfs(node->right,s,deleted);
                return deleted ? NULL : node;
        }

};





// class Solution {
        
//         // TC : O(N)
//         // N -> NO. OF NODES IN THE TREE
        
//     vector<TreeNode*> res;
    
// public:
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
//             set<int>s;
//             for(auto x:to_delete)s.insert(x);
//             TreeNode* temp = new TreeNode(-1,root,NULL);
//             dfs(temp,s);
//             if(s.count(root->val)==0) res.push_back(root);
//             return res;
           
//     }
// private:
//         void dfs(TreeNode* & root, set<int>& s)
//         {
//                 if(root==NULL)return;
        
//                 dfs(root->left,s);
//                 dfs(root->right,s);
//                 if(root->left && s.count(root->left->val))
//                 {
//                      TreeNode* temp = root->left;
//                         if(temp->left) res.push_back(temp->left);
//                         if(temp->right)res.push_back(temp->right);
//                         root->left = NULL;
//                 }
//                 if(root->right && s.count(root->right->val))
//                 {
//                      TreeNode* temp = root->right;
//                         if(temp->left) res.push_back(temp->left);
//                         if(temp->right)res.push_back(temp->right);
//                         root->right = NULL;
//                 }
                
                
//         }
// };