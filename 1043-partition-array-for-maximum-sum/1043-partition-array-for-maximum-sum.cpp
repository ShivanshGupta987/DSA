class Solution {
int dp[501]={};
        // TC : O(n*K)
        // SC : O(n)
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k,int pos=0, int res=0) {
        if(pos<arr.size() && dp[pos]!=0) return dp[pos];
            for(int i=1, mv = 0; i<=k && i+pos<= arr.size(); i++){
                    mv = max(mv, arr[pos+i-1]);
                    res = max(res, mv*i + maxSumAfterPartitioning(arr,k,pos+i));
            }
            return dp[pos]=res;
    }
};