//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    
public:
    int countFriendsPairings(int n) 
    { 
    
        int mod = (int)1e9+7;
        vector<long long int>dp(n+1);
        dp[0]=0; dp[1]=1;dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i] = (dp[i-1] + ((dp[i-2])%mod*(i-1))%mod)%mod;
        }
        return dp[n];
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends