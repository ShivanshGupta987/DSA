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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* slow = dummyhead, *fast = dummyhead;
        int delay = n;
        while(delay--){
            fast = fast->next;
        }
        while(fast && fast->next){
            slow =  slow->next;
            fast = fast->next;
            cout<<"("<<slow->val<<","<<fast->val<<")\n";
        }
        assert(slow->next != NULL);
        // if(slow->next==NULL) return NULL;
        slow->next = slow->next->next;
        return dummyhead->next;
    }
};