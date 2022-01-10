class Solution {
        // TC: O(N^2)
        // SC:O(N)
        private : 
        int dp(int n,vector<int>&mem){
                if(n<=1)return mem[n]=1;
                if(mem[n]>-1)return mem[n];
                
                int ans=0;
                for(int i=1;i<=n;i++){
                        ans+=dp(i-1,mem)*dp(n-i,mem);
                }
                return mem[n]=ans;
        }
public:
    int numTrees(int n) {
            
        vector<int>mem(n+1,-1);
            mem[0]=mem[1]=1;
           return dp(n,mem);
            
    }
};