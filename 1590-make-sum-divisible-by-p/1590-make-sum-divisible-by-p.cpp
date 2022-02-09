class Solution {
public:
        // TC:O(N)
        // SC:O(p)
    int minSubarray(vector<int>& nums, int p) {
        int len=INT_MAX;
            int n=nums.size();
            int need=0;
            for(auto n:nums)need = (need+n)%p;
            if(need==0)return 0;
           
            unordered_map<int,int>mp{{0,-1}};
            int sum=0;
            for(int i=0;i<n;i++){
                    sum = (sum+nums[i])%p;
                    mp[sum]=i;
                    int req= (sum-need+p)%p;
                  
                    if(mp.count(req)){
                          len=min(len,i-mp[req]);
                    }
                    
            }
            return len==nums.size()?-1:len;
    }
};