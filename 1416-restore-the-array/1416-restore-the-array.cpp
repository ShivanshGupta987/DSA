class Solution {
        
        // TC : O(N* log K)
        // SC : O(N)
    const int mod = 1e9 + 7;
    int digits(int k){
            int ans =0;
            for(;k!=0;(k/=10,ans++)){}
            return ans;
    }
public:
    int numberOfArrays(string s, int k) {
            
            int n = s.size();
            vector<int>dp(n+1);
            dp[n]=1;
            for(int i=n-1;i>=0;i--){
                   if(s[i]=='0')continue;
                   int j=digits(k);
                   long long num = 0; 
                
                   for(int j=1;j<=k && i+j<=n;j++){
                           num = num*10 + s[i+j-1]-'0';
                           if(num>k)break;
                           dp[i]= (dp[i] + dp[i+j]) % mod;
                          
                   }
            }
            return dp[0];
    }
};