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
        vector<int>sums;
public:
    int maxLevelSum(TreeNode* root) {
        
            dfs(root,1);
            return distance(sums.begin(),max_element(sums.begin(),sums.end())) + 1;
           
    }
private: 
        void dfs(TreeNode* root, size_t level){
                    
                if(root== NULL)return;
                sums.resize(max(sums.size(),level));
                sums[level-1] += root->val;
                dfs(root->left,level+1);
                dfs(root->right,level+1);
            }
};


//class Solution {
//         // TC : O(N)
//         // N -> NO. OF NODES IN THE TREE

// public:
//     int maxLevelSum(TreeNode* root) {
        
//             queue<TreeNode*> q;
//             q.push(root);
//             int max_sum = INT_MIN;
//             int level = 0;
//             int ans;
//             while(!q.empty()){
                    
//                     level++;
//                     int sum = 0;
                    
//                     for(int i = q.size()-1; i>=0; i--){
                            
//                             TreeNode* temp = q.front();
//                             q.pop();
                            
//                             sum += temp->val;
//                             if(temp->left) q.push(temp->left);
//                             if(temp->right)q.push(temp->right);
//                     }
//                     if(sum>max_sum) {
//                             max_sum = sum;
//                             ans = level;
//                     } 
//             }
//             return ans;
//     }
// };