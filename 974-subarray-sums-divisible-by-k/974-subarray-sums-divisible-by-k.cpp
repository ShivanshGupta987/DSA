class Solution {
        // TC: O(N)
        // SC: O(K)
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int ans =0;
            int n=nums.size();
            unordered_map<int,int>mp;
            mp.insert({0,0});
            int sum=0;
            
            for(int i=0;i<n;i++){
                    sum+=nums[i];
                    int rem = sum%k;
                    if(rem<0)rem=rem+k;
                    if(mp.find(rem)!=mp.end()){
                            mp[rem]++;
                            ans+=mp[rem];
                           
                    }
                    
                    else mp[rem]=0;
            }
            return ans;
    }
};