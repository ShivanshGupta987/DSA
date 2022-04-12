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
    int maxLevelSum(TreeNode* root) {
        
            queue<TreeNode*> q;
            q.push(root);
            int max_sum = INT_MIN;
            int level = 0;
            int ans;
            while(!q.empty()){
                    
                    level++;
                    int sum = 0;
                    
                    for(int i = q.size()-1; i>=0; i--){
                            
                            TreeNode* temp = q.front();
                            q.pop();
                            
                            sum += temp->val;
                            if(temp->left) q.push(temp->left);
                            if(temp->right)q.push(temp->right);
                    }
                    if(sum>max_sum) {
                            max_sum = sum;
                            ans = level;
                    } 
            }
            return ans;
    }
};