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
        // SC : O(H)
        // N -> NO. OF NODES IN THE TREE
        // H -> HEIGHT OF THE TREE
public:
    int sumEvenGrandparent(TreeNode* root) 
    {
            return helper(root,false,false);       
    }
        
        // p -> parent
        // gp -> grandparent
        int helper(TreeNode* root, bool p, bool gp){
                if(root==nullptr) return 0;
                int value = root->val;
                int sum = 0;
                if(gp) sum+=value;
                return sum + helper(root->left,value%2==0,p) + 
                        helper(root->right,value%2==0,p);
        }
};