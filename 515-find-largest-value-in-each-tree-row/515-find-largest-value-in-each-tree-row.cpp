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
    vector<int> largestValues(TreeNode* root) {
     
            if(root==nullptr)return {};
            queue<TreeNode*>q;
            q.push(root);
            vector<int>res;
            
            while(!q.empty())
            {
                    int maxx = INT_MIN;
                  for(int i=q.size()-1;i>=0;i--)
                  {
                          TreeNode* temp = q.front();
                          q.pop();
                          maxx = max(maxx,temp->val);
                          if(temp->left) q.push(temp->left);
                          if(temp->right)q.push(temp->right);
                  }
                    res.push_back(maxx);
            }
            return res;
    }
};