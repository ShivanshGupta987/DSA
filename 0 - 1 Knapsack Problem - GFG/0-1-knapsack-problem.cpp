//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   
     int dp[1001][1001];
    int rec(int val[], int wt[], int left_cap, int n, int ind){
        if(ind>=n) return 0;
        
        if(dp[left_cap][ind]!=-1) return dp[left_cap][ind];
        int res = 0;
        // picking the current element 
        if(wt[ind] <= left_cap) 
            res = max(res, val[ind] + rec(val,wt,left_cap-wt[ind], n, ind+1));
        // not picking the current element
        res = max(res, rec(val,wt,left_cap,n,ind+1));
        return dp[left_cap][ind] = res;
        
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof dp);
       return rec(val, wt, W, n, 0);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends