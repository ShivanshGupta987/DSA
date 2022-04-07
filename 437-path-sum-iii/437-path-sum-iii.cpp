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
        // TC : O(N)
        // N -> NO. OF NODES
        // SC : O(H)
        // H -> HEIGHT OF THE TREE
        int ans;
public:
    int pathSum(TreeNode* root, int targetSum) {
        
            ans = 0;
            unordered_map<long long,int>mp;
            mp[0]=1;
            dfs(root, targetSum, mp,0);
            return ans;
    }
        
        void dfs(TreeNode* root, int target, unordered_map<long long,int>& mp, long long pre){
                
                 if(root==NULL) return;
                 pre += root->val;
                 
                if(mp.find(pre-target)!=mp.end())  
                        ans += mp[pre-target];
                mp[pre]++;
                dfs(root -> left, target , mp , pre);
                dfs(root -> right, target, mp, pre);
                mp[pre]--;
        }
};