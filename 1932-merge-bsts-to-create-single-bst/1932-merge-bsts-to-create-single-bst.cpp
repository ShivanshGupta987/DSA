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
        // TC : O(3*N)
        // SC : O(N)
        
    bool validate_BST(TreeNode* node , unordered_map<int,TreeNode*>& mp,
                       int min_left = INT_MIN, int max_right = INT_MAX){
         
            if(node == NULL) return true;
            
            if(node->val <= min_left || node->val >= max_right) return false;
            
            if(node->left == node->right){
                    int val = node->val;
                    auto it = mp.find(val);
                    if(it != mp.end() && node != it->second){
                            node->left= it->second->left;
                            node->right = it->second->right;
                            mp.erase(it);
                    }
            }
            
            return validate_BST(node->left,mp,min_left, node->val) && validate_BST(node->right,mp,node->val, max_right);
            
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        
            // to store the root-tree pair 
            // since every root can be identified uniquely
            unordered_map<int,TreeNode*>mp;
            unordered_map<int,int>cnt;// to record count of root value and and leave-value
            
            for(auto t:trees){
                    mp[t->val] = t;
                    ++cnt[t->val];
                    ++cnt[t->left ? t->left->val:0];
                    ++cnt[t->right ? t->right->val : 0];
            }
            
            
            for(auto &t : trees){
                if(cnt[t->val]==1) return validate_BST(t,mp) && mp.size()==1 ?t:NULL;
            }
            
            return NULL;
            
            
    }
};