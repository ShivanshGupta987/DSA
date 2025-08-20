/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // TC : O(M+N)
    // SC : O(1)
    int get_length(ListNode* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        int len1 = get_length(headA);
        int len2 = get_length(headB);
        ListNode* temp1 = headA, *temp2 = headB;
        while(len1 > len2){
            temp1 = temp1->next;
            len1--;
        }
        while(len2 > len1){
            temp2 = temp2->next;
            len2--;
        }
        // if(temp1 == NULL || temp2 == NULL) return NULL;
        while(temp1 && temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};