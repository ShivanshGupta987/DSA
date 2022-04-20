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

// USING ITERATIVE METHOD
//         // TC : O(N)
//         // SC : O(H)
//         // N -> NO. OF NODES IN THE TREE
//         // H -> HEIGHT OF THE TREE
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        
            vector<TreeNode*>s;
            s.push_back(new TreeNode(pre[0]));
            for(int i=1, j=0;i<pre.size();i++)
            {
                    TreeNode* root = new TreeNode(pre[i]);
                    
                    while(s.back()->val == post[j])
                    {
                           s.pop_back(); j++;
                    }
                    
                    if(!s.back()->left) s.back()->left = root;
                    else s.back()->right = root;
                    s.push_back(root);
            }
            return s[0];
    }
};



// // USING DFS

// class Solution {
        
//         // TC : O(N)
//         // SC : O(H)
//         // N -> NO. OF NODES IN THE TREE
//         // H -> HEIGHT OF THE TREE
        
//         int pre_ind=0;
//         int pos_ind=0;
// public:
//     TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
         
//             TreeNode* root = new TreeNode(pre[pre_ind++]);
            
//             if(root->val != post[pos_ind]) 
//                     root->left = constructFromPrePost(pre,post);
//             if(root->val != post[pos_ind])
//                     root->right = constructFromPrePost(pre,post);
//             pos_ind++;
//             return root;
//     }
// };