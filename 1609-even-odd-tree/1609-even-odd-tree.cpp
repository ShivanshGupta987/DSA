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
    bool isEvenOddTree(TreeNode* root) {
        
            queue<TreeNode*> q;
            q.push(root);
            
            int level = 0;
            while(!q.empty())
            {
                    int prev;
                    if(level % 2 == 0) prev = INT_MIN;
                    else prev = INT_MAX;
                   for(int i = q.size()-1;i>=0;i--)
                   {  
                           TreeNode* temp = q.front();
                           q.pop();
                           
                           int num = temp->val;
                           
                           if(level % 2 == 0 && ( num<=prev || num % 2 ==0 )) 
                                   return false;  
                           if(level % 2 == 1 && (num>=prev || num % 2 == 1))
                              return false;
                           
                           if(temp->left) q.push(temp->left);
                           if(temp->right) q.push(temp->right);
                           
                           prev = num;
                   }
                    level++;
            }
            return true;
    }
};