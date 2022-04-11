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
// SC : O(H)
//  N -> NO. OF NODES IN THE TREE
// H -> HEIGHT OF THE TREE
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
            if(root==NULL)return 0;
            queue<TreeNode*> q;
            q.push(root);
            
            int res = 0;
            
            while(!q.empty())
            {
                    res = 0;
                   for(int i = q.size()-1; i>=0 ; i--)
                   {
                           TreeNode* temp = q.front();
                           q.pop();
                           res += temp->val;
                           
                           if(temp->left) q.push(temp->left);
                           if(temp->right) q.push(temp->right);
                   }
            }
            
            return res;
            
    }
};












// // TC : O(N)
// // SC : O(H)
// //  N -> NO. OF NODES IN THE TREE
// // H -> HEIGHT OF THE TREE
// class Solution {
// public:
//     int deepestLeavesSum(TreeNode* root) {
//         if(root==NULL)return 0;
//             int h = height(root)-1;
//             return dfs(root,0,h);
//     }
//         int height(TreeNode* root){
//                 if(root==nullptr) return 0;
//                 return max(height(root->left)+1 , height(root->right)+1);
//         }
//         int dfs(TreeNode* root, int level, int h){
//                 if(root==nullptr)return 0;
//                 if(root->left==root->right && level==h) return root->val;
//                 return dfs(root->left,level+1,h) + dfs(root->right,level+1,h);
//         }
// };