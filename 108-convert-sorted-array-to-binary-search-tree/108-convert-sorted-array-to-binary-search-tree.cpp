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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_BST(nums,0,nums.size()-1);
    }

    TreeNode* build_BST(vector<int>& arr, int left, int right){
            if(left>right) return NULL;
            int mid = left + (right-left)/2;
            TreeNode* root = new TreeNode(arr[mid]);
            root->left = build_BST(arr,left,mid-1);
            root->right = build_BST(arr,mid+1,right);
            return root;
    }
};