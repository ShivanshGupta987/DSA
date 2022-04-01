/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 4 Liner solution
// TC : O(N)
// N -> NO. OF NODES
// SC : O(H)
// H -> HEIGHT OF THE TREE 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
      if(!root || root == p || root == q) return root;
            TreeNode* left = lowestCommonAncestor(root->left, p , q);
            TreeNode* right = lowestCommonAncestor(root->right, p , q);
              return left ? right ? root : left : right;
           // return !left ? right : !right ? left : root;
            
         
    }
};