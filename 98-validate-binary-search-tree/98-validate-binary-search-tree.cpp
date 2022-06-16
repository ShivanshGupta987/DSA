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
public:
    bool isValidBST(TreeNode* root, long long int min_value = -1e10 , long long int max_value = 1e10) {
        
            if(root==NULL)return true;
            long long int val = root->val;
            if(val<=min_value || val>=max_value) return false;
            return isValidBST(root->left,min_value,val) && isValidBST(root->right, val, max_value);  
    }
};