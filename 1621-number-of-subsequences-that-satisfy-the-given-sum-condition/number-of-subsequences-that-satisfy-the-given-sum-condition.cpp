class Solution {
    // TC : O(n log n)
    // SC : O(1)
    const long long mod = 1e9+7;
    long long power(long long base, int pow){
        if(pow==0) return 1;
        long long res = 0;
        long long x = power(base, pow>>1);
        x*=x;
        x%=mod;
        if(pow%2){
            res = (base*x)%mod;
        }
        else res = x;
        return res;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long cnt = 0;
        for(int i=0;i<n;i++){
            int left = i, right=n-1;
            int rem = target-nums[i];
            int end = -1;
            while(left<=right){
                int mid = left + (right-left)/2;
                if(nums[mid] <= rem){
                    left = mid+1;
                    end = mid;
                }
                else right = mid-1;
            }
            if(end==-1) break;
            cnt += power(2, end-i);
            cnt %=mod;
        }
        return cnt;

    }
};