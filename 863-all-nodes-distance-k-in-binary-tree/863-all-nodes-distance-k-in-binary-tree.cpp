/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
unordered_map<TreeNode*,TreeNode*>parent;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            
            dfs(root);
            unordered_map<TreeNode*,bool>visited;
            queue<TreeNode*>q;
            q.push(target);
            visited[target]=true;
            int cur_level = 0;
            while(!q.empty()){
                    
                    int size = q.size();
                    if(cur_level++ == k)break;
                    for(int i=0;i<size;i++){
                                
                            TreeNode* current = q.front();
                            q.pop();
                            
                            if(current->left && !visited[current->left]){
                                    q.push(current->left);
                                    visited[current->left]=true;
                            }
                            
                            if(current->right && !visited[current->right]){
                                    q.push(current->right);
                                    visited[current->right]=true;
                            }
                            
                            if(parent[current] && !visited[parent[current]]){
                                    q.push(parent[current]);
                                    visited[parent[current]]=true;;
                            }
                            
                
                    }                
            }
            
            vector<int>res;
            while(!q.empty()){
                    TreeNode* cur = q.front();
                    q.pop();
                    res.push_back(cur->val);
            }
            return res;
        
    }
        
    void dfs(TreeNode* root){
            
            if(root->left){
                    parent[root->left]=root;
                    dfs(root->left);
            }
            
            if(root->right){
                    parent[root->right]=root;
                    dfs(root->right);
            }
            
    }
};


// TC : O(N)
// SC : O(N)

// class Solution {
// vector<int>ans;
// bool target_found = false;
// bool target_over = false;
// int target_val ;
// int K;

// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
//             target_val = target->val;
//             K=k;
//             dfs(root,k);
//             return ans;
            
            
//     }
        
//     void dfs(TreeNode* root, int k , int dist=0){
       
//             if(!root)return;
//             if(k==0 && target_found){
//                     ans.push_back(root->val);
//                     return;
//             } 
//             if(dist==K && target_over){
//                     ans.push_back(root->val);
//             }
//             if(root->val == target_val)
//                     target_found = true;
//             if(target_found){
//                     dfs(root->left,k-1,dist);
//                     dfs(root->right,k-1,dist);
//             }
//             if(root->val == target_val){
//                     target_found = false;
//                     target_found = true;
//             }
//             if(target_over){
//                     dfs(root->left,-1,dist+1); 
//                     dfs(root->right,-1,dist+1);
//             }
                    
            
//     }
// };