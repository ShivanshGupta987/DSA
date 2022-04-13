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
        // N -> NO. OF NODES IN THE TREE
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
            if(root == NULL)return {};
            vector<vector<int>>res;
            
            queue<TreeNode*>q;
            q.push(root);
            
            while(!q.empty())
            {
                    vector<int>vec;
                    for(int i=q.size()-1;i>=0;i--)
                    {
                            TreeNode* temp = q.front();
                            q.pop();
                            vec.push_back(temp->val);
                            if(temp->left) q.push(temp->left);
                            if(temp->right)q.push(temp->right);
                            
                    }
                    res.push_back(vec);
                    vec.clear();
            }
            return res;
    }
};