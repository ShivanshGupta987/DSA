/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// TC : O(N)
// SC : O(log N)
// N -> no. of nodes in the linked list
class Solution {
ListNode* head;
public:
    TreeNode* sortedListToBST(ListNode* head) {
            this->head = head;
            return build_BST(0, length(head)-1);
    }

    TreeNode* build_BST(int left, int right){
            if(left > right) return NULL;
            
            int mid = left + (right-left)/2;
            TreeNode* left_subtree = build_BST(left,mid-1);
            TreeNode* root = new TreeNode(head->val);
            head = head->next;
            root->left = left_subtree;
            root->right = build_BST(mid+1,right);
            
            return root;
              
    }

    int length(ListNode* head){
            int ans = 0;
            while(head != NULL){
                    head = head->next;
                    ans++;
            }
            return ans;
    }
};