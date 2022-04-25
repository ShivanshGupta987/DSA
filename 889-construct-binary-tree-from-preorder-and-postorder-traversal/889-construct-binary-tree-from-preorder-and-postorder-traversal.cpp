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
        
        // INTUTION BEHIND THE PROBLEM
        
//         preorder :         [root] [left subtree] [right subtree]
//         postorder :        [left subtree] [right subtree][root]
        
//         First of all we try to divide the whole tree in the two part : left subtree 
//         and right subtree
                
//         preorder : 1 2 4 5 3 6 7 
                
//         postorder: 4 5 2 6 7 3 1

//         here  to divide preorder into left and right subtree , we have to know about 
//         where the left subtree ends 
//         to know about it : 
//         1) store all the value and index pair in hashmap 'mp'
//         2) Referring the above e.g. , here to get the left subtree part we find 
//                 the postorder index of the value just next to our root in preorder.
//                 root value : 1
//                 next to root in preorder : 2
//                 Now, mp[2] gives the index of postorder of 2
//         3) now , we can easily find out the length of indices of left and right subtree in preorder and postorder traversal 
//         4) we repeat this process until we find our answer
        
unordered_map<int,int>mp;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
            int n = preorder.size();
            for(int i=0;i<postorder.size();i++)
                    mp.insert({postorder[i],i});
            
        return utility(preorder,postorder,0,n-1,0,n-1);    
            
    }

private:
       TreeNode* utility(vector<int>& pre, vector<int>& post, int preStart, int preEnd, int postStart, int postEnd){
                
                    if(preStart>preEnd) return NULL;
                 
                    TreeNode* root = new TreeNode(pre[preStart]);
                    if(preStart==preEnd) return root;
                    int idx = mp[pre[preStart+1]];
                    int offset = idx - postStart;
                    
   root->left = utility(pre,post,preStart+1,preStart+offset+1,postStart,idx);
   root->right = utility(pre,post,preStart+offset+1+1,preEnd,idx+1,postEnd-1);
   return root;
        }
};


// // USING ITERATIVE METHOD
// //         // TC : O(N)
// //         // SC : O(H)
// //         // N -> NO. OF NODES IN THE TREE
// //         // H -> HEIGHT OF THE TREE
// class Solution {
// public:
//     TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        
//             vector<TreeNode*>s;
//             s.push_back(new TreeNode(pre[0]));
//             for(int i=1, j=0;i<pre.size();i++)
//             {
//                     TreeNode* root = new TreeNode(pre[i]);
                    
//                     while(s.back()->val == post[j])
//                     {
//                            s.pop_back(); j++;
//                     }
                    
//                     if(!s.back()->left) s.back()->left = root;
//                     else s.back()->right = root;
//                     s.push_back(root);
//             }
//             return s[0];
//     }
// };



// // USING DFS
// KEY IDEA : 
// if we found root->val == post[pos_ind] it means we have explored that root completly hence we need to end the function call and go to one level up

// class Solution {
        
//         // TC : O(N)
//         // SC : O(H)
//         // N -> NO. OF NODES IN THE TREE
//         // H -> HEIGHT OF THE TREE
        
//         int pre_ind=0;
//         int pos_ind=0;
// public:
//     TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
         
//             TreeNode* root = new TreeNode(pre[pre_ind++]);
            
//             if(root->val != post[pos_ind]) 
//                     root->left = constructFromPrePost(pre,post);
//             if(root->val != post[pos_ind])
//                     root->right = constructFromPrePost(pre,post);
//             pos_ind++;
//             return root;
//     }
// };