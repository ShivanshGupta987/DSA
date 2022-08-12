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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* i = list1;
        ListNode* j = list2;
        
        if(!i) return j;
        if(!j) return i;
        
        ListNode* cur = i;
        if(i->val <= j->val){
            i=i->next;
        }
        else {
            cur = j;
            j=j->next;
        }
        
        ListNode* head = cur;
        
        while(i && j){
            if(i->val <= j->val){
                cur->next = i;
                i = i->next;
            }
            else {
                cur->next = j;
                j = j->next;
            }
            cur = cur->next;
        }
        
        if(i) cur->next = i;
        else cur->next = j;
           
        return head;
    }
   
};