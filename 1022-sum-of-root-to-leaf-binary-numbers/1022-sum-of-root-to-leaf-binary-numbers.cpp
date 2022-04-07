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
        // N -> NO. OF NODES IN THE BINARY TREE
        // H -> HEIGHT OF THE BINARY TREE
        
        int ans;
public:
    int sumRootToLeaf(TreeNode* root ) {
        
            preorder(root,0);
            return ans;
           
    }
        
        void preorder(TreeNode* root, int num){
                
                        if(!root)return;
                        num = (num << 1) | root->val;
                        if(root->left == root->right) ans += num;
                        preorder(root->left,num);
                        preorder(root->right,num);
                
        }
        
    
};