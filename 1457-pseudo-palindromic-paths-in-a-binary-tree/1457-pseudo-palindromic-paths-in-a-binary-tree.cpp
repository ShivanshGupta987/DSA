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
       
        int ans;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
     
            ans = 0;
            dfs(root,0);
            return ans;
    }
        
           void dfs(TreeNode* root, int map){
                
                if(root==NULL)return;
                   
                   map = map ^ (1<<root->val);
                if(root->left == root->right){
                        
                        if( (map & (map-1))==0) ans++;
                        return;
                }
                dfs(root->left,map);
                dfs(root->right,map);
        }
        
      
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//         // TC : O(N)
//         // SC : O(H)
//         // N -> NO. NODES IN THE TREE
//         // H -> HEIGHT OF THE TREE
//         int ans;
// public:
//     int pseudoPalindromicPaths (TreeNode* root) {
        
//             ans = 0;
//             unordered_set<int> s;
//             dfs(root,s);
//             return ans;
//     }
       
        
//         void dfs(TreeNode* root, unordered_set<int>s){
                
//                 if(root==NULL)return;
//                 if(root->left == root->right){
//                         if(s.count(root->val)) s.erase(root->val);
//                         else s.insert(root->val);
//                         if(s.size() <= 1) ans++;
//                         return;
//                 }
//                 if(s.count(root->val)) s.erase(root->val);
//                 else s.insert(root->val);
                
//                 dfs(root->left,s);
//                 dfs(root->right,s);
//         }
// };