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
        
unordered_map<int,int>mp;
int pos = 0; // current index while traversing preorder array
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
          for(int i=0;i<inorder.size();i++){
                  mp.insert({inorder[i],i});
          }
          return dfs(preorder,0,preorder.size()-1);  
                  
    }
private:
     TreeNode* dfs(vector<int>& preorder, int left, int right)
     {
             if(left>right) return NULL;
             TreeNode* root = new TreeNode(preorder[pos++]);
             root->left = dfs(preorder,left,mp[root->val]-1);
             root->right = dfs(preorder,mp[root->val]+1,right);
             return root;
             }
};

// class Solution {
//         int pre_ind = 0;
//         int in_ind = 0;
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         return dfs(preorder,inorder,INT_MIN);
//     }
// private: 
//         TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int stop)
//         {
//                 if(pre_ind>=preorder.size()) return NULL;
//                 if(inorder[in_ind]==stop) 
//                 {
//                         in_ind++; return NULL;
//                 }
                
//                 TreeNode* root = new TreeNode(preorder[pre_ind++]);
                
//                 root->left = dfs(preorder,inorder,root->val);
//                 root->right = dfs(preorder,inorder,stop);
//                 return root;
//         }
// };
