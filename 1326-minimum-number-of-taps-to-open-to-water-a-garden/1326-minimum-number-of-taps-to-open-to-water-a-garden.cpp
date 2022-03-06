class Solution {
        // TC : O(N*N)
        // SC : O(N)
        
const int MAX = 100000;
        
public:
    int minTaps(int n, vector<int>& ranges) {
        
            vector<int>dp(n+1,MAX);
            dp[0]=0;
            for(int i=1;i<=n;i++){
                    for(int j=0;j<=i;j++){
                    if(j+ranges[j]>=i ) dp[i] = min( dp[max(0,j-ranges[j])] +1, dp[i]);     
                    }
                  
            }
            
            return dp[n] == MAX ? -1 : dp[n]; 
    }
};