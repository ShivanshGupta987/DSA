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
        
        // TC : O(N)
        // N -> NO. OF NODES IN THE TREE
int val;
int depth;
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
            if(root==NULL) return nullptr;
            this->val = val;
            this->depth = depth;
            if(depth==1)
            {
                 TreeNode* temp = new TreeNode(val,root,nullptr);
                 return temp;
            }
            dfs(root,1);
            return root;
    }
private: 
        void dfs(TreeNode* & root, int d)
        {
                if(root==nullptr) return;
                if(d==depth-1)
                {
                  TreeNode* new_node = new TreeNode(val,root->left,NULL);
                  root->left = new_node;
                  
                  new_node = new TreeNode(val,NULL,root->right);
                  root->right = new_node;
                  return;
                }
                dfs(root->left,d+1);
                dfs(root->right,d+1);
        }
};