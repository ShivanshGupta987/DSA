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


/* The functions which 
builds the segment tree */
int min(int x,int y){
    return x<y?x:y;
}
int build(int ss, int se, int si, int arr[],int* st){
    if(ss==se)return st[si]=arr[ss];
    
        int mid=ss+(se-ss)/2;
        return st[si]=min(build(ss,mid,2*si+1,arr, st) , build(mid+1, se , 2*si+2 ,arr,st));

}

int *constructST(int arr[],int n)
{
  //Your code here
  int x=(int)(ceil(log2(n)));
  int size = 2*(int)pow(2,x)-1;
  int* st = new int [size];
  build(0,n-1,0,arr,st);
  return st;
}


/* The functions returns the
 min element in the range
 from a and b */
 int rmq(int ss, int se, int si, int qs, int qe, int st[])
{
//Your code here
 if(qe<ss || se<qs)return INT_MAX;
 if(qs<=ss && qe>=se) return st[si];

     int mid= ss+(se-ss)/2;
     return min(rmq(ss,mid,2*si+1,qs,qe,st), rmq(mid+1,se,2*si+2,qs,qe,st));

 
}
int RMQ(int st[] , int n, int qs, int qe)
{
//Your code here
if(qs<0 || qe>n-1 || qe<qs)return -1;
 return rmq(0,n-1,0,qs,qe,st);
}