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
        // TC : O(N)
        // SC : O(H)
        // N -> NO. OF NODES IN THE TREE
        // H -> HEIGHT OF THE TREE
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
            if(dfs(root,target))root=NULL;
            return root;
    }
private:
        bool dfs(TreeNode* & root, int target){
                if(root==nullptr) return false;
                if(dfs(root->left,target)) root->left = nullptr;
                if(dfs(root->right,target)) root->right = nullptr;
                if(root->left==root->right && root->val == target)return true;
                return false;
                
        }
};