class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        
    if(nums.size()<3 || nums[0]>0)return {};
    vector<vector<int>>res;      
    unordered_map<int,int>mp;
            for(int i=0;i<nums.size();i++)mp[nums[i]]=i;
            
            
          for(int i=0;i<nums.size()-1;i++){
                  
                          for(int j=i+1;j<nums.size()-1;j++){
                              int target=-(nums[i]+nums[j]);
                              if(mp.count(target) && mp[target]>j){
                                res.push_back({nums[i],nums[j],target});      
                              }
                                 j= mp.find(nums[j])->second;
                          }
                  i=mp.find(nums[i])->second;
          }
            return res;
            
            
    }
};