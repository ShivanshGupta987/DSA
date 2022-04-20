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
// N -> NO. OF NODES IN THE TREE
// H -> HEIGHT OF THE TREE

// KEY IDEA :
//                    let say we have a following subtree -
                           
//                            34
//                           /  \
//                          12   8
//         as we traverse preorder array to make tree, if we go to the left of the root 
//         then at some point of time we will encounter with 34 of inorder array it means 
//         - 
//         1) left subtree is done 
//         2) Now just go one level up and fill the right of that root
        
//         hence as we go inside left subtree we set out stop target as 34 and for 
//         right subtree we set ancestor of 34 as stop target


class Solution {
        int pre_ind = 0;
        int in_ind = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,inorder,INT_MIN);
    }
private: 
        TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int stop)
        {
                if(pre_ind>=preorder.size()) return NULL;
                if(inorder[in_ind]==stop) 
                {
                        in_ind++; return NULL;
                }
                
                TreeNode* root = new TreeNode(preorder[pre_ind++]);
                
                root->left = dfs(preorder,inorder,root->val);
                root->right = dfs(preorder,inorder,stop);
                return root;
        }
};