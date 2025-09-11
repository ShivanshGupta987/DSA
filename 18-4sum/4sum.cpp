class Solution {
    // TC : O(N*N*N)
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1, right = n-1;
                long long goal = (long long)target-nums[i]-nums[j];
                while(left<right){
                    long long sum = (long long)nums[left] + nums[right];
                    if(sum < goal){
                        left++;
                    }
                    else if(sum==goal){
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++, right--;
                    }
                    else right--;
                    while(left<right && left>j+1 && nums[left]==nums[left-1])left++;
                    while(left<right && right<n-1 && nums[right]==nums[right+1])right--;

                }
            }
            
        }
        return res;

    }
};