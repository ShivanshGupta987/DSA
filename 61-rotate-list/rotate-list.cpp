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
    // TC : O(N)

public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==nullptr) return NULL;
        ListNode* cur = head, *tail = nullptr;
        int len = 0;
        while(cur){
            len++;
            tail = cur;
            cur = cur->next;
        }
        k = k%len;
        if(k==0) return head;
        int steps = len-k-1;
        cur = head;
        ListNode *new_head = NULL;
        while(steps--){
            cur = cur->next;
        }
        new_head = cur->next;
        tail->next = head;
        cur->next = nullptr;
        
        return new_head;

    }
};