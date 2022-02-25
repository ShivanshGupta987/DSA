class Solution {
        // TC : O(S*N)
        // SC : O(S)
        // S -> sum of all elements / 2
        // N -> total no. of elements
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
            if(sum&1)return false;
            vector<bool>dp((sum/2)+1,false);
            int S=sum/2;
            dp[0]=true;
            for(int i=0;i<nums.size();i++){
                    for(int s=S; s>=0; s--){
                            if(s-nums[i]>=0 && dp[s-nums[i]]) dp[s]=true;
                    }
            }
            for(int i=0; i<=S;i++){
                    cout<<i<<" ";
                    if(dp[i])cout<<1;
                    else cout<<0;
                    cout<<endl;
                    
            }
            return dp[S];
    }
};