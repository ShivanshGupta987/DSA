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
        
        int pre_ind=0;
        int pos_ind=0;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
         
            TreeNode* root = new TreeNode(pre[pre_ind++]);
            
            if(root->val != post[pos_ind]) 
                    root->left = constructFromPrePost(pre,post);
            if(root->val != post[pos_ind])
                    root->right = constructFromPrePost(pre,post);
            pos_ind++;
            return root;
    }
};