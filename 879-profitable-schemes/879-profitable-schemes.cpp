class Solution {
        #define mod 1000000007;
public:
    int profitableSchemes(int n, int minProfit, vector<int>& grp, vector<int>& pr) {
        int P=minProfit;
            int G=n;
            int c=grp.size();  // Max. no. of crimes
            vector<vector<int>>dp(G+1,vector<int>(P+1,0));
            for(int g=0;g<G+1;g++)dp[g][0]=1;
            for(int i=0;i<c;i++){
               for(int g=G;g>=0;g--){
                       for(int p=P;p>=0;p--){
   if(g>=grp[i])  dp[g][p]= (dp[g][p] + dp[max(g-grp[i],0)][max(p-pr[i],0)]) %mod;
                               
                            //   cout<<dp[g][p]<<" ";
                       }
                      // cout<<endl;
               }  
                  //  cout<<endl<<endl;
                    
            }
           return  dp[G][P];
    }
};