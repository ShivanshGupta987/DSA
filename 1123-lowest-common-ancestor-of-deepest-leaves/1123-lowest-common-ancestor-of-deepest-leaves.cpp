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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       return helper(root).first; 
            
    }

    pair<TreeNode* , int> helper(TreeNode* root){
            
            if(root == NULL) return {NULL, 0};
            
            auto left = helper(root->left);
            auto right = helper(root -> right);
            
            if(left.second > right.second) return {left.first , left.second + 1};
            else if(left.second < right.second) return {right.first , right.second +1};
            else return {root,left.second+1};
            
            
    }
};



// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
        
//         // TC : O(N)
//         // SC : O(H)
//         // N -> NO. OF NODES
//         // H -> HEIGHT OF THE TREE
        
//     TreeNode* lca;
//     int deepest = 0;
// public:
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
//             fun(root, 0);
//             return lca;
//     }
        
//     int fun(TreeNode* root , int depth){
            
//             deepest = max(deepest , depth);
            
//             if(root == NULL) return depth;
            
//             int left = fun(root->left, depth+1);
//             int right = fun(root-> right , depth +1);
            
//             if(left == deepest && right == deepest ) lca = root;
            
//             return max(left , right);
//     }
// };