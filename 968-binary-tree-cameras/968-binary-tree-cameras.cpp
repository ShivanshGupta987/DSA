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

// -------------INTUTION BEHIND THE ALGORITHM------------------
// STATE - 0 : node need a camera
// STATE - 1 : node is covered
// STATE - 2 : node has a camera

// TC : O(N)
// SC: O(N)
class Solution {
int ans = 0;
public:
    int minCameraCover(TreeNode* root) {
        
            if(dfs(root)==0){
                    ans++;
            }
            return ans;
    }
        
    int dfs(TreeNode* root){
            if(!root)return 1;
            int left = dfs(root->left);
            int right = dfs(root->right);
            
            // if any one of the children need a camera
            if(left==0 || right ==0) {
                    ans++;
                    return 2;
            }
            
            // if children of the node are covered and any one of them has a camera
            if(left==2 || right==2){
                    return 1;
            }
            
            // if children of node are covered and any one one of those children don't have camera
            return 0;
    }
};