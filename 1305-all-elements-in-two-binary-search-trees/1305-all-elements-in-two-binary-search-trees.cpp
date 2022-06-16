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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
            vector<int>arr1,arr2;
            inorder(root1,arr1);
            inorder(root2,arr2);
            return merge_list(arr1,arr2);           
    }
        
    void inorder(TreeNode* root, vector<int>& arr){
            if(root==NULL)return;
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
    }
    vector<int> merge_list(vector<int>& a, vector<int>& b){
            int m = a.size(), n = b.size();
            int i=0,j=0;
            vector<int>res;
            while(i<m && j<n){
                    if(a[i]<=b[j]) res.push_back(a[i++]);
                    else res.push_back(b[j++]);
            }
            
            while(i<m) res.push_back(a[i++]);
            while(j<n) res.push_back(b[j++]);
            return res;
    }
};