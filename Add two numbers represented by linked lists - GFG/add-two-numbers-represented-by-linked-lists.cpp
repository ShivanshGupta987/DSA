//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{   
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
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        reverse(&first);
        reverse(&second);
        
        Node* temp1 = first, * temp2 = second;
        int carry = 0;
        Node* head = new Node(0);
        Node* temp = head;
        while(temp1 && temp2){
            int x = temp1->data;
            int y = temp2->data;
            temp->next = new Node((x+y+carry)%10);
            carry = (x+y+carry)/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
            temp = temp->next;
        }
        
        while(temp1){
            int x = temp1->data;
            temp->next = new Node((x+carry)%10);
            carry = (x+carry)/10;
            temp = temp->next;
            temp1=temp1->next;
        }
        while(temp2){
            int x = temp2->data;
            temp->next = new Node((x+carry)%10);
            carry = (x+carry)/10;
            temp = temp->next;
            temp2=temp2->next;
        }
        if(carry) temp->next = new Node(carry);
        head = head->next;
        reverse(&head);
        return head;
        
    }
        
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends