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
// N -> NO. OF NODES IN THE TREE
// TC : O(H)
// H -> HEIGHT OF THE TREE
class Solution {
 vector<vector<int>>res;
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      
            int d =  depth(root);
            res = vector<vector<int>>(d,vector<int>());
            dfs(root,d-1);
            return res;
    }
private : 
        int depth(TreeNode* root)
        {
                if(!root) return 0;
                return max(depth(root->left),depth(root->right)) + 1;
        }
        
        void dfs(TreeNode* root, int level)
        {
                if(!root)return;
                res[level].push_back(root->val);
                dfs(root->left,level-1);
                dfs(root->right,level-1);
        }

        
};