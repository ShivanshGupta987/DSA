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
        
        // SC : O(2^(N-1))
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
            vector<double>res;
            queue<TreeNode*>q;
            q.push(root);
            
            double avg = 0;
            
            while(!q.empty())
            {
                    avg = 0;
                 double n = q.size();
                 for(int i=q.size()-1;i>=0;i--)
                 {
                         TreeNode* temp = q.front();
                         q.pop();
                         avg += temp->val;
                         if(temp->left) q.push(temp->left);
                         if(temp->right) q.push(temp->right);
                 }
                    res.push_back(avg/n);
                      
            }
            return res;
            
            
    }
};