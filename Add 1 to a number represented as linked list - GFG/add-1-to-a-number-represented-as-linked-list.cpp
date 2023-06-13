//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
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
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        reverse(& head);
        
        Node* temp = head;
        bool carry = false;
        Node* prevone = nullptr;
        while(temp){
            if(temp->data<9){
                temp->data+=1;
                carry = false;
                break;
            }
            carry = true;
            temp->data = 0;
            prevone = temp;
            temp = temp->next;
        }
        if(carry) prevone->next = new Node(1);
        reverse(& head);
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
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends