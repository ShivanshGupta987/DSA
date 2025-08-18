/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // TC : O(1)
public:
    void deleteNode(ListNode* node) {
        // overwrite data 
        node->val = node->next->val;

        ListNode* nextNode = node->next;
        // bypass next node and connect it to next of next
        node->next = node->next->next;

        delete(nextNode);

    }
};