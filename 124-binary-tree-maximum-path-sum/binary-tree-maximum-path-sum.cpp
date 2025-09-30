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
    // PROBABLE APPROACH IS SIMILAR TO CADANE ON THE BINARY TREE
    // TC : O(H)
    // SC : O(H)
    int max_path_sum = -4e7;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int left_sum = helper(root->left);
        int right_sum = helper(root->right);
        max_path_sum = max(max_path_sum, root->val + max({0, left_sum, right_sum, left_sum + right_sum}));
        return root->val + max({0, left_sum, right_sum});
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_path_sum;
    }
};