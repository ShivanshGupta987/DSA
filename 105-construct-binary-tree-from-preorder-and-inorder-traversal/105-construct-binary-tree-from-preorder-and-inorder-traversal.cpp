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
        int pre_pos = 0;
        int in_pos = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,INT_MIN);
    }
        
private:
        TreeNode* dfs(vector<int>& pre, vector<int>& in, int stop)
        {
                 if(pre_pos>=pre.size()) return NULL;
                 if(stop==in[in_pos])
                 {
                         in_pos++;
                         return NULL;
                 }
                 TreeNode* temp = new TreeNode(pre[pre_pos++]);
                 temp->left = dfs(pre,in,temp->val);
                 temp -> right = dfs(pre,in,stop);
                 return temp;
        }
};