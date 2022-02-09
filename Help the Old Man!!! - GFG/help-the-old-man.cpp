// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> shiftPile(int N, int n){
        vector<int>list;
         helper(N,1,2,3,n,list);
         return list;
    }
    private: void helper(int N,int s,int a,int d,int& n,vector<int>&list){
        if(N==0)return;
        helper(N-1,s,d,a,n,list);
        n--;
        if(n==0){
            list={s,d}; return;
        }
        helper(N-1,a,s,d,n,list);
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends