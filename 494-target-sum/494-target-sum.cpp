class Solution {
        // TC: O(2^N)
        // N ->  nums.size()
        
        int dp(int ind, int target,int sum, vector<int>&nums,map<pair<int,int>,int>&mem){
                
                // Base cases
             if(ind<0 && sum==target)return 1; 
             if(ind<0)return 0;
                if(mem.find({ind,sum})!=mem.end())return mem[{ind,sum}];
                
                // decisions
                
                int positive = dp(ind-1,target,sum+nums[ind],nums,mem);
                int negative = dp(ind-1,target,sum-nums[ind],nums,mem);
                return mem[{ind,sum}]=positive + negative;
                
        }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
            map<pair<int,int>,int>mem;
      return dp(nums.size()-1,target,0,nums,mem); 
           
    }
};