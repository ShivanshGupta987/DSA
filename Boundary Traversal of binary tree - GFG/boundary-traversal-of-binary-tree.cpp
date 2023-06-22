//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    void bottomview(Node* root, vector<int>& v){
        if(root==nullptr) return;
        if(root->left==root->right)v.push_back(root->data);
        bottomview(root->left,v);
        bottomview(root->right,v);
    }
    void leftview(Node* root, vector<int>& v){
        if(root==nullptr || root->left==root->right) return;
        v.push_back(root->data);
        if(root->left) leftview(root->left,v);
        else if(root->right) leftview(root->right,v);
        
    }
    void rightview(Node* root, vector<int>& v){
        if(root==nullptr || root->left==root->right) return;
        v.push_back(root->data);
        if(root->right) rightview(root->right,v);
        else if(root->left) rightview(root->left,v);
        
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        queue<Node*>q;
        q.push(root);
        vector<int>left_view;
        vector<int>right_view;
        vector<int>bottom_view;
        leftview(root->left,left_view);
        rightview(root->right,right_view);
        bottomview(root,bottom_view);
        vector<int>res;
        res.push_back(root->data);
        if(root->left==root->right) return res;
        for(int i=0;i<left_view.size();i++){
            res.push_back(left_view[i]);
        }
        for(int i=0;i<bottom_view.size();i++){
            res.push_back(bottom_view[i]);
        }
        for(int i=right_view.size()-1;i>=0;i--){
            res.push_back(right_view[i]);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends