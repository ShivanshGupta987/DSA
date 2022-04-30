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
// N-> NO. OF NODES IN THE TREE

// SC : O(H)
// H -> HEIGHT OF THE TREE
class Solution {
int pos = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {     
           return helper(preorder,INT_MAX); 
    }

private:
        TreeNode* helper(vector<int>& pre,int maxx){
             
                if(pos>=pre.size() || pre[pos]>maxx)return NULL;
                
                TreeNode* root = new TreeNode(pre[pos]);
                if(pre[pos]<maxx){
                        pos++;
                        root->left = helper(pre,root->val);
                        root->right = helper(pre,maxx);
                }
                return root;
                
        }
};