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

#define ll long long int
class Solution {

        // TC : O(S)
        // S -> trav.size()
        // SC : O(N)
        //  N -> NO. OF NODES IN THE TREE
        
public:
    TreeNode* recoverFromPreorder(string trav) {
       
            vector<TreeNode*>stack;
            
            ll val;
            for(int i=0,level;i<trav.size();)
            {
                    for(level=0;trav[i]=='-';i++) level++;
                    
                    for(val=0;i<trav.size() && trav[i]!='-';i++) val = 10*val + (trav[i]-'0');
                    
                    TreeNode* node = new TreeNode(val);
                    
                    while(stack.size()>level)stack.pop_back(); 
                    
                    if(!stack.empty()){
                            if(!stack.back()->left) stack.back()->left = node;
                            else stack.back()->right = node;
                    }
                    stack.push_back(node);
            }
            return stack[0];
    }
};