//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
public:
    int subsetXOR(vector<int> arr, int n, int K) {
        // TC : O(M*N)
        // SC : O(M*N)
        // code here
        int m = (1<<7);
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        dp[0][0]=1;
        
        // dp[i][j] : no. of subsets having value xor j from subsets of arr[0...i-1]
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j] = dp[i-1][j]+dp[i-1][j^arr[i-1]];
            }
        }
        return dp[n][K];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends