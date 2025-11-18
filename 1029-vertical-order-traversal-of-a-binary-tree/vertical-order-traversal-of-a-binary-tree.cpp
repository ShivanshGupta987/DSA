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
    map<int, map<int,vector<int>>>mp;
    void dfs(TreeNode* root, int x, int y){
        if(root==NULL) return;
        dfs(root->left, x-1, y+1);
        mp[x][y].push_back(root->val);
        dfs(root->right, x+1, y+1);        
   }
   
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      
        vector<vector<int>>res;
        dfs(root, 0, 0);
        for(auto &[key1, mp2] : mp){
            vector<int>temp;
            for(auto &[key2, vec] : mp2){
                sort(vec.begin(), vec.end());
                for(int x : vec){
                    temp.push_back(x);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};