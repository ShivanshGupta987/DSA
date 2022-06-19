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
int ans; // total minimum moves
public:
    int distributeCoins(TreeNode* root) {
        
            ans = 0;
            dfs(root);
            return ans;
    }
    int dfs(TreeNode* root){
            if(!root) return 0;
            int left_moves = dfs(root->left);
            int right_moves = dfs(root->right);
            ans += abs(left_moves) + abs(right_moves);
            return root->val + left_moves + right_moves - 1;
            
    }
};