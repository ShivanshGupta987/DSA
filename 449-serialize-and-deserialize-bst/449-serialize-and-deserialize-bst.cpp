/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
        // TC : O(N)
        // SC : O(N)
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
            string res;
            queue<TreeNode*>q;
            if(root==nullptr) return "";
            q.push(root);
            while(!q.empty()){
                    TreeNode* cur = q.front();
                    q.pop();
                    
                    if(cur == nullptr){
                            res += "#,"; continue;
                    }
                    else res += to_string(cur->val)+',';
                    q.push(cur->left);
                    q.push(cur->right);
            }
            cout<<res;
            return res;
            
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
             if(data.empty()) return nullptr;
            stringstream s(data);
            string str;
            getline(s,str,',');
            TreeNode* root = new TreeNode(stoi(str));
            
            queue<TreeNode*>q;
            q.push(root);
            
            while(!q.empty()){
                    TreeNode* temp = q.front();
                    q.pop();
                    
                    getline(s,str,',');
                    
                    if(str=="#") temp->left = nullptr;
                    else
                    {
                         TreeNode* leftNode = new TreeNode(stoi(str));                              temp->left = leftNode;
                            q.push(leftNode);
                    }
                    
                    getline(s,str,',');
                    if(str=="#") temp->right = nullptr;
                    else{
                          TreeNode* rightNode = new TreeNode(stoi(str));
                           temp->right = rightNode;
                            q.push(rightNode);
                    }
            }
            return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;