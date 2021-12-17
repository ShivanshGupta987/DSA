class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
            // TC:O(N)
            // SC:O(1)
        double max_sum=0;
            
            for(int i=0;i<k;i++){
                    max_sum+=nums[i];
            }
            double curr_sum=max_sum;
            for(int i=k;i<nums.size();i++){
                    curr_sum+= nums[i]-nums[i-k];
                    max_sum=max(max_sum,curr_sum);
            }
            return max_sum/k;
    }
};