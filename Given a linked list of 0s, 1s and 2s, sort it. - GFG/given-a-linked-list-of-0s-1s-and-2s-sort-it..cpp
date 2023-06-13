//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
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
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        // declaring three dummy nodes
        Node* zerod = new Node(0);
        Node* oned = new Node(1);
        Node* twod = new Node(2);
        
        Node* temp = head;
        
        Node* zero = zerod, *one = oned, *two = twod;
        
        while(temp){
            Node* nextone = temp->next;
            if(temp->data==0){
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->data==1){
                one->next = temp;
                one = one->next;
                
            }
            else{
                two->next = temp;
                two = two->next;
               
            }
            temp->next = nullptr;
            temp = nextone;
            // temp = temp->next;
        }
        
        zero->next = (oned->next)? oned->next : twod->next;
        one->next = twod->next; 
        // two->next = nullptr;
        head = zerod->next;
        delete zerod;
        delete oned;
        delete twod;
        
        return head;
        
        // vector<int>arr;
        // Node* temp = head;
        // while(temp){
        //     arr.push_back(temp->data);
        //     temp = temp->next;
        // }
        // int n = arr.size();
        // int zero = -1, first = -1;
        // for(int i=0;i<n;i++){
        //     if(arr[i]==0){
        //         swap(arr[i],arr[first+1]);
        //         swap(arr[first+1],arr[zero+1]);
        //         zero++;first++;
        //     }
        //     else if(arr[i]==1){
        //         swap(arr[i],arr[first+1]);
        //         first++;
        //     }
        // }
        
        // return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends