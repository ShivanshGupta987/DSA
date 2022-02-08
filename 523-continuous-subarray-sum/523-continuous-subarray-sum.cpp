class Solution {
public:
        // TC: O(N)
        // SC: O(1)
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
            int n=nums.size();
    
    
            mp.insert({0,-1});
            int sum=0;
            for(int i=0;i<n;i++){
                  sum+=nums[i];
                   int rem =sum%k;
                    if(mp.find(rem)!=mp.end()){
                         if(i-mp[rem]>1){
                                 return true;
                                
                         }
                    }
                    else mp[rem]=i;
            }
            return false;
    }
};