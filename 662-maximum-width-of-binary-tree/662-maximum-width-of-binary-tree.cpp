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

#define ll long long int
class Solution {
        
        // TC : O(N)
        // N -> NO. OF NODES IN THE TREE
      
    ll max_width;
public:

    int widthOfBinaryTree(TreeNode* root) {
        max_width = 0;
        vector<ll>left_idx_at;
        dfs(root,0,1,left_idx_at);
        return max_width;   
    }

private: 
        void dfs(TreeNode* root, ll level, ll idx, vector<ll> & left_idx_at)
        {
                if(root==NULL)return ;
                if(level>=left_idx_at.size()) left_idx_at.push_back(idx);
                max_width = max(max_width, idx-left_idx_at[level]+1);
                dfs(root->left,level+1,2*(idx-left_idx_at[level]),left_idx_at);
                dfs(root->right,level+1,2*(idx-left_idx_at[level])+1,left_idx_at);
                
        }

};