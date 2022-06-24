/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TC : O(N)
// SC : O(N)
class Solution {
vector<int>res;
unordered_map<TreeNode*,int>mp;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            
            find(root,target);
            
            dfs(root,target,k,mp[root]);
            return res;
        
            }

        int find(TreeNode* root,TreeNode* target){
                if(root==NULL)return -1;
                if(root==target){
                        mp[root]=0;
                        return 0;
                }
                int left = find(root->left,target);
                if(left>=0){
                        mp[root] = left+1;
                        return left+1;
                }
                
                int right = find(root->right,target);
                if(right>=0){
                        mp[root] = right+1;
                        return right+1;
                }
                return -1;

        }
        
        void dfs(TreeNode* root, TreeNode* target, int k, int length){
                
                if(root == NULL)return;
                
                if(mp.count(root)){
                        length = mp[root];
                }
                
                if(length == k) res.push_back(root->val);
                dfs(root->left,target,k,length+1);
                dfs(root->right,target,k,length+1);

                
        }
};