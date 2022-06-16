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
    TreeNode* convertBST(TreeNode* root) {
        
            if(root==NULL)return NULL;
            convertBST(root->right);
            root->val = pre_val + root->val;
            pre_val = root->val;
            convertBST(root->left);
            return root;
    }
};