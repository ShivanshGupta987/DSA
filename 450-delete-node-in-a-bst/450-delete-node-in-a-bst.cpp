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
// TC : O(H)
// SC : O(H)
// H -> HEIGHT OF THE TREE

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
            if(!root) return nullptr;
            if(key < root->val) root->left = deleteNode(root->left,key);
            else if(key > root->val) root->right = deleteNode(root->right,key);
            else
            {
                    if(!root->left && !root->right) return NULL; // no child
                    
                    if(!root->left || !root->right) // one child is present
                            return root->left ? root->left:root->right;
                   
                    // both childs are present
                    TreeNode* temp = root->left;
                    
                    while(temp->right) temp = temp->right;
                    
                    root->val = temp->val;
                    root->left = deleteNode(root->left,temp->val);
            }
            return root;
    }
};