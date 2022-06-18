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
// SC : O(N)
class Solution {
TreeNode* ans = NULL;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
            if(root==NULL) return nullptr;
            if(root->val == val) return ans = root;
            else if(root->val > val ) searchBST(root->left,val);
            else searchBST(root->right,val);
            return ans;
            
    }
};