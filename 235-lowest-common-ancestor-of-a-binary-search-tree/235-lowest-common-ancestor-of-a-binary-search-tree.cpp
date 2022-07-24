/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
        // TC : O(h)
        // h -> height of the tree
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans=root;
          
        int x = p->val;
        int y = q->val;
        
        if(x>y) swap(x,y); 
          
        while((ans->val < x || ans-> val > y) && (ans->val != x) && (ans->val !=y)){
                if(x < ans->val && y < ans->val) ans = ans->left;
                else ans = ans -> right;
        }
            
        return ans; 
            
    }
        
};