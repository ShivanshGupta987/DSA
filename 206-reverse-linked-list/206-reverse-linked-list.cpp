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
    // ITERATIVE SOLUTION
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// // RECURSIVE SOLUTION

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(!head || !head->next)return head;
//         auto node= reverseList(head->next);
//         head->next->next = head;
//         head->next = nullptr;
//         return node;  
//     }
// };