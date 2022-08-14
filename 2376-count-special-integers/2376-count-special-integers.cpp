class Solution {
    
int dp[11][2][1024];

int rec(string &s , int tight=1, int pos=0, int mask=0){
    // Base Case
    if(pos==s.size()) return mask!=0;
    
    if(dp[pos][tight][mask]!=-1) return dp[pos][tight][mask];
    
    int ub = tight ? s[pos]-'0' : 9;
    
    int ans = 0;
    for(int i=0;i<=ub;i++){
       if(mask & (1<<i)) continue;
        int new_mask = (mask==0 && i==0 ? mask : (mask | (1<<i)));
        ans+= rec(s,tight & (i==ub),pos+1,new_mask);
    }
    
    return dp[pos][tight][mask] = ans;
}

public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return rec(s);
    }
};