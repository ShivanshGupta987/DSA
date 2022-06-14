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
  
   vector<TreeNode *> helper(int start, int end){
           
           if(start>end) return {nullptr};
           if(start == end) return {new TreeNode(start)};
           vector<TreeNode*>left_subtree;
           vector<TreeNode*>right_subtree;
           vector<TreeNode*>all_trees;
           
           for(int cur_root_val = start; cur_root_val<=end ; cur_root_val++){
                   left_subtree = helper(start,cur_root_val-1);
                   right_subtree = helper(cur_root_val+1,end);
                   
                   for(auto & lst : left_subtree){
                           for(auto & rst : right_subtree){
                                   TreeNode* cur_root = new TreeNode(cur_root_val);
                                   cur_root->left = lst;
                                   cur_root->right = rst;
                                   all_trees.push_back(cur_root);
                           }
                   }
           }
           return all_trees;
   }
public:
    vector<TreeNode*> generateTrees(int n) {
     
            return helper(1,n);
    }
};