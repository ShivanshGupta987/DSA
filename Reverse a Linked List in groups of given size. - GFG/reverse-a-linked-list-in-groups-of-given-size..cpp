//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    
    public:
    void reverse(node** head){
        node* temp = *head;
        node* prevone = nullptr;
        while(temp){
            node* nextone = temp->next;
            temp->next = prevone;
            prevone = temp;
            temp = nextone;
        }
        *head = prevone;
    }
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* temp = head;
        int cnt = 0;
        if(k==1) return head;
        node* prevone = nullptr;
        node* group_head = nullptr;
        node* last_group_tail = nullptr;
        while(temp){
            cnt++;
            if(cnt==1) group_head = temp;
            node* nextone = temp->next;
            if(cnt==k || nextone == nullptr){
                temp->next = nullptr;
                node* group_tail = group_head;
                reverse(&group_head);
                if(last_group_tail) last_group_tail->next = group_head;
                else head = group_head;
                last_group_tail = group_tail;
                cnt = 0;
            }
            temp = nextone;
        }
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends