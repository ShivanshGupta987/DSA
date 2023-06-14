// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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


class Solution
{
    void reverse(Node** head){
        Node* temp = *head;
        Node* prevone  = nullptr;
        while(temp){
            Node* nextone = temp->next;
            temp->next = prevone;
            prevone = temp;
            temp = nextone;
        }
        *head = prevone;
    }
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        
        int len = 0;
        Node* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        if(len==k) return head;
        reverse(&head);
        
        temp = head;
        int times = len-k;
        Node* tail = head;
        while(times-->1){
            tail = tail->next;
        }
        Node* second_list_head = tail->next;
        Node* second_list_tail = second_list_head;
        tail->next = nullptr;
        Node* first_list_head = head;
        Node* first_list_tail = first_list_head;
        reverse(&first_list_head);
        reverse(&second_list_head);
        first_list_tail->next = second_list_head;
        return first_list_head;
        
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends