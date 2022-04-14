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
vector<int>res;
public:
    vector<int> rightSideView(TreeNode* root) {
  
            dfs(root,0);
            return res;
    }
private:
        void dfs(TreeNode* root, int depth)
        {
                if(root==NULL)return;
                if(depth == res.size()) res.push_back(root->val);
                dfs(root->right,depth+1);
                dfs(root->left,depth+1);      
        }
};