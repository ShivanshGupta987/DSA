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
public:
        // TC : O(N)
        // N-> NO. OF NODES 
        // SC: O(H)
        // H-> HEIGHT OF THE TREE
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        
            dfs(root,"");
            return res;
    }

    void dfs(TreeNode* root , string s ){
            if( root->left == NULL && root->right == NULL) {
                    if(s.empty()) s+= to_string(root->val);
                    else s += "->" + to_string(root->val);
                    res.push_back(s); return ;
            }
            if(s.empty()) s+= to_string(root->val);
            else s += "->" + to_string(root->val);
            if(root->left != NULL)dfs(root->left, s);
            if(root->right != NULL) dfs(root->right,s);
            
            
    }
};