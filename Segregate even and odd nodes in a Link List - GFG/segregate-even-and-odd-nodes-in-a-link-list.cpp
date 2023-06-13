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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* dummy = new Node(2);
        dummy->next = head;
        head = dummy;
        Node* first = head; // points at the last even number in segregated list
        Node* temp = head;
        while(first->next){
            if(first->next->data % 2 == 0){
                first = first->next;
                temp = temp->next;
            }
            else break;
        }
        while(temp->next!=nullptr){
            if((temp->next->data & 1)==0){
                // 1st step : Remove the even value node
                Node* evenNode = temp->next;
                temp->next = temp->next->next;
                
                // 2nd step : Insert the even value node after first node
                evenNode->next = first->next;
                first->next = evenNode;
                first = first->next; 
            }
            else temp = temp->next;
        }
        head = head->next;
        dummy->next = nullptr;
        delete dummy;
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends