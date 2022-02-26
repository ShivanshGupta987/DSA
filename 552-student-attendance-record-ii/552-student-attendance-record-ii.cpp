class Solution {
        const int mod  = (int)1e9+7;
        int N;   
       
    int dfs(int i, int absent, int late,vector<vector<vector<int>>>& mem){
            if(i==N){return 1;} 
            
            
            if(mem[i][absent][late]!=-1)return mem[i][absent][late];
            int ans=0;
            
            // choice 1 - absent
            
            if(absent<1) ans = (ans + dfs(i+1,absent+1,0,mem)) % mod;
            
            // choice 2 - late
            
            if(late<=1)ans =( ans + dfs(i+1,absent,late+1,mem)) % mod;
           
            // choice 3 - present 
            
            ans = (ans + dfs(i+1,absent,0,mem)) % mod;
       
            return mem[i][absent][late]=ans;
    }
public:
    int checkRecord(int n) {
            N=n;
        vector<vector<vector<int>>>mem(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return dfs(0,0,0,mem);
    }
};