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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
            if(root==NULL)return {};
            queue<TreeNode*>q;
            q.push(root);
            vector<int>res;
            while(!q.empty())
            {
                    for(int i=q.size()-1;i>=0;i--)
                    {
                            TreeNode* temp = q.front();
                            q.pop();
                            if(i==0)res.push_back(temp->val);
                            if(temp->left) q.push(temp->left);
                            if(temp->right) q.push(temp->right);
                    }
            }
            return res;
            
    }
};