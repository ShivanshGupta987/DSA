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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // SLOW AND FAST POINTER
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         int len = 0;
//         auto cur = head;
//         while(cur){
//             len++;
//             cur = cur->next;
//         }
//         int moves = (len/2);
//         while(moves--){
//             head = head->next;
//         }
//         return head;
//     }
// };