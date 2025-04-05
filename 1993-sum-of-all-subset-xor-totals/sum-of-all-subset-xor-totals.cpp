class Solution {
    // TC : O(2^N)
    // SC : O(1)
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int subset=0;subset<(1<<n);subset++){
            int cur_xor = 0;
            for(int i=0;i<32;i++){
                if((subset>>i)&1) cur_xor ^= nums[i];
            }
            ans += cur_xor;
        }
        return ans;
    }
};