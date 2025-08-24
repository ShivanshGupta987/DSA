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
    // SC : O(1)
    void reverse(ListNode** head){
        ListNode* cur = *head, *prevNode = NULL, *nextNode = NULL;
        while(cur!=NULL){
            nextNode = cur->next;
            cur->next = prevNode;
            prevNode = cur;
            cur = nextNode;
        }
        *head = prevNode;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow;
        reverse(&head2);

        ListNode* temp1 = head, *temp2 = head2;
        while(temp1 && temp2){
            if(temp1->val != temp2->val) return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
        
    }
};