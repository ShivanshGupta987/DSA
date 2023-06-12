//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    void reverse(Node** head_ref){
        Node* temp = *head_ref;
        Node* prevone = nullptr;
        while(temp){
            Node* nextone = temp->next;
            temp->next = prevone;
            prevone = temp;
            temp = nextone;
        }
        *head_ref = prevone;
        
    }
    bool compare(Node* list1, Node* list2){
        while(list1 && list2){
            if(list1->data != list2->data) return false;
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head->next==nullptr) return true;
        Node* slow = head, *fast = head;
        Node* prevone = nullptr;
        while(fast && fast->next){
            prevone = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast) slow = slow->next;
        Node* second_list_head = slow;
        Node* first_list_head = head;
        Node* reverse_second_list_head = second_list_head;
        reverse(&reverse_second_list_head);
        bool ans = compare(first_list_head,reverse_second_list_head);
        reverse(&reverse_second_list_head);
        second_list_head = reverse_second_list_head;
        
        first_list_head->next = second_list_head;
        return ans;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends