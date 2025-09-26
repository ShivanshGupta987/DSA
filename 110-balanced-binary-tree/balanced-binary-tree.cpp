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
    // TC : O(NO. OF NODES IN TREE)
    bool isBalance = true;
    int ht(TreeNode* root){
        if(root==NULL || !isBalance) return 0;
        int left_ht = ht(root->left);
        int right_ht = ht(root->right);
        if(abs(right_ht-left_ht)>1) isBalance = false;
        return 1 + max(left_ht, right_ht);
    }
public:
    bool isBalanced(TreeNode* root) {
        ht(root);
        return isBalance;
    }
};