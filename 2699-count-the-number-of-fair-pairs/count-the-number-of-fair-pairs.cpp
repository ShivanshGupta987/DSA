class Solution {
    // TC : O(N)
    // SC : O(1)
    long long solve(vector<int>& nums, long long value){
        int n = nums.size();
        int left = 0, right = n-1;
        long long cnt = 0;
        while(left<right){
            long long sum = nums[left] + nums[right];
            if(sum < value){
                cnt += right-left;
                left++;
            } 
            else right--;
        }
        return cnt;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return solve(nums, upper+1) - solve(nums, lower);

    }
};