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
    int res=INT_MAX;
public:
    int minDiffInBST(TreeNode* root, int left = -1e6 , int right = 1e6) {
        
            if(root == NULL) return res;
            if(root->left) {
                    res = min(res,abs(root->val - root->left->val));
                    res = min(res, abs(left - root->left->val));
            }
            if(root->right){
                res = min(res,abs(root->val - root->right->val));
                res = min(res, abs(right-root->right->val));
            }
            minDiffInBST(root->left , left, root->val);
            minDiffInBST(root->right , root->val , right);
            return res;
    }
};