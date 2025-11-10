/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return nullptr;
        TreeNode* found1 = solve(root->left, p, q);
        TreeNode* found2 = solve(root->right, p, q);
        if((found1 || found2) && (root==p || root==q)) return root;
        else if(found1 && found2) return root;
        else if(root==p || root==q) return root;
        else return found1!=nullptr? found1:found2;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};