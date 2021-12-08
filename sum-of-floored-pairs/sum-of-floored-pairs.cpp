class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        
           const int mod= 1e9 +7;
           int N = nums.size();
           sort(nums.begin(),nums.end());
           unsigned long ans=0;
            
           for(int i=0;i<N;){
                   int j=i+1;
                   
                   while(j<N && nums[j-1]==nums[j])j++;
                   
                   long dup = j-i;
                   ans = (ans + dup*dup % mod)%mod;
                   
                   while(j<N){
                           int div= nums[j]/nums[i]; int bound = (div+1)*nums[i];
                           int next = lower_bound(nums.begin()+j,nums.end(),bound)-nums.begin();
                           ans = (ans + (next-j)*dup % mod * div % mod) % mod;
                           j=next;
                   }
                   i+=dup;
           }
            return ans % mod;
    }
};