// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends

int minVal(int x, int y) { return (x < y)? x: y; } 

// A utility function to get the 
// middle index from corner indexes. 
int getMid(int s, int e) { return s + (e -s)/2; } 

/* A recursive function to get the
minimum value in a given range 
of array indexes. The following 
are parameters for this function. 

    st --> Pointer to segment tree 
    index --> Index of current node in the 
           segment tree. Initially 0 is 
           passed as root is always at index 0 
    ss & se --> Starting and ending indexes 
                of the segment represented 
                by current node, i.e., st[index] 
    qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index) 
{ 
    // If segment of this node is a part 
    // of given range, then return 
    // the min of the segment 
    if (qs <= ss && qe >= se) 
        return st[index]; 

    // If segment of this node
    // is outside the given range 
    if (se < qs || ss > qe) 
        return INT_MAX; 

    // If a part of this segment
    // overlaps with the given range 
    int mid = getMid(ss, se); 
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1), 
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2)); 
} 

// Return minimum of elements in range
// from index qs (query start) to 
// qe (query end). It mainly uses RMQUtil() 
int RMQ(int *st, int n, int qs, int qe) 
{ 
    // Check for erroneous input values 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        cout<<"Invalid Input"; 
        return -1; 
    } 

    return RMQUtil(st, 0, n-1, qs, qe, 0); 
} 

// A recursive function that constructs
// Segment Tree for array[ss..se]. 
// si is index of current node in segment tree st 
int constructSTUtil(int arr[], int ss, int se,
                                int *st, int si) 
{ 
    // If there is one element in array,
    // store it in current node of 
    // segment tree and return 
    if (ss == se) 
    { 
        st[si] = arr[ss]; 
        return arr[ss]; 
    } 

    // If there are more than one elements, 
    // then recur for left and right subtrees 
    // and store the minimum of two values in this node 
    int mid = getMid(ss, se); 
    st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1), 
                    constructSTUtil(arr, mid+1, se, st, si*2+2)); 
    return st[si]; 
} 

/* Function to construct segment tree 
from given array. This function allocates
memory for segment tree and calls constructSTUtil() to 
fill the allocated memory */
int *constructST(int arr[], int n) 
{ 
    // Allocate memory for segment tree 

    //Height of segment tree 
    int x = (int)(ceil(log2(n))); 

    // Maximum size of segment tree 
    int max_size = 2*(int)pow(2, x) - 1; 

    int *st = new int[max_size]; 

    // Fill the allocated memory st 
    constructSTUtil(arr, 0, n-1, st, 0); 

    // Return the constructed segment tree 
    return st; 
} 

// /* The functions which 
// builds the segment tree */
// int min(int x,int y){
//     return x<y?x:y;
// }
// int build(int ss, int se, int si, int arr[],int* st){
//     if(ss==se)return st[si]=arr[ss];
//     if(ss<se){
//         int mid=ss+(se-ss)/2;
//         return st[si]=min(build(ss,mid,2*si+1,arr, st) , build(mid+1, se , 2*si+2 ,arr,st));
//     }
// }

// int *constructST(int arr[],int n)
// {
//   //Your code here
//   int x=(int)(ceil(log2(n)));
//   int size = 2*(int)pow(2,x)-1;
//   int* st = new int [size];
//   build(0,n-1,0,arr,st);
//   return st;
// }


// /* The functions returns the
//  min element in the range
//  from a and b */
//  int rmq(int ss, int se, int si, int qs, int qe, int st[])
// {
// //Your code here
//  if(qe<ss || se<qs)return INT_MAX;
//  if(qs<=ss && qe>=se) return st[si];

//      int mid= ss+(se-ss)/2;
//      return st[si] = min(rmq(ss,mid,2*si+1,qs,qe,st), rmq(mid+1,se,2*si+2,qs,qe,st));

 
// }
// int RMQ(int st[] , int n, int qs, int qe)
// {
// //Your code here
// if(qs<0 || qe>n-1 || qe<qs)return -1;
//  return rmq(0,n-1,0,qs,qe,st);
// }