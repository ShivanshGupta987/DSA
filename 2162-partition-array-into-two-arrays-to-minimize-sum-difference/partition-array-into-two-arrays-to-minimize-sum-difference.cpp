class Solution {
    // where N = 2*n
    // TC : O(N*(2^(N/2)))
    // SC : O(2^(N/2))
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;

        int sum = 0;
        for(int x : nums){
            sum += x;
        }

        vector<vector<int>>left(n+1);
        vector<vector<int>>right(n+1);

        for(int mask=0; mask<(1<<n); mask++){
            int cnt = 0, sum1 = 0, sum2 = 0;
            for(int i=0;i<n;i++){
                if((mask>>i)&1){
                    cnt++;
                    sum1 += nums[i];
                    sum2 += nums[i+n];
                }
            }
            left[cnt].push_back(sum1);
            right[cnt].push_back(sum2);
        }

        for(int sz=0; sz<=n; sz++){
            sort(right[sz].begin(), right[sz].end());
        }

        int res = 1e9;

        // where sz : size of the left part
        for(int sz=1; sz<=n; sz++){
            for(int left_sum : left[sz]){
                // we aim to reach close to target(mid) which is sum(nums)/2
                int target = (sum-2*left_sum)/2;
                auto it = lower_bound(right[n-sz].begin(), right[n-sz].end(), target);

                if(it!=right[n-sz].end()){
                    res = min(res, abs(sum - 2*(left_sum + *it)));
                }
                if(it!=right[n-sz].begin()){
                    it--;
                    res = min(res, abs(sum - 2*(left_sum + *it)));
                }
            }
            
        }
        return res;
    }
};