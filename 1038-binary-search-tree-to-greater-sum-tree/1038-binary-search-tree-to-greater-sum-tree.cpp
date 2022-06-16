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
class Solution {
int pre_val=0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        
            if(root==NULL)return NULL;
            bstToGst(root->right);
            root->val = pre_val + root->val;
            pre_val = root->val;
            bstToGst(root->left);
            return root;
    }
};