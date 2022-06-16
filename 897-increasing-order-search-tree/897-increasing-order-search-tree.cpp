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
        TreeNode* ans = NULL;
        TreeNode* pre = NULL;

public:
    TreeNode* increasingBST(TreeNode* root) {
        
            if(root->left) increasingBST(root->left);
            TreeNode* cur = new TreeNode(root->val);
            if(pre == NULL){
                    pre = cur;
                    ans = pre;
            }
            else{
                    pre->right = cur;
                    pre = pre->right;
            }
            if(root->right) increasingBST(root->right);
            return ans;
              
    }
};