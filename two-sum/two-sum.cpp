class Solution {
public:
        int FindInd(vector<int>& nums , int num){
                for(int i=0;i<nums.size();i++){
                        if(nums[i]==num)return i;
                }
                return 0;
        }
     
    vector<int> twoSum(vector<int>& nums, int target) {
        
         unordered_map<int,int>s;
            int n=nums.size();
            for(int i=0;i<n;i++){
                    s.insert({nums[i],i});
            }
            
            for(int i=0;i<n;i++){
                    auto it= s.find(target-nums[i]);
                    if(it !=s.end() && it->second!=i) {
                            return {i,it->second};
                    }
            }
            return {0,0};
    }
};