class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
            int ans=0;
                 for(int i=0;i<nums.size();i++){
                         
                         auto it=mp.find(k-nums[i]);
                         if(it!=mp.end() && it->second>0  ){
                                 cout<<it->second<<" ";
                                 ans++;
                                 mp[k-nums[i]]--;
                                 continue;
                         }
                         mp[nums[i]]++;
                 }
     return ans;       
    }
};