class Solution {
    // TC : O(N1* log N2 * log (2e10))
    // SC : O(1)
    long long count(vector<int>& nums1, vector<int>& nums2, long long target){
        long long sum = 0;
        int n2 = nums2.size();
        for(auto &x : nums1){
            int left = 0, right = n2-1;
            while(left<=right){
                int mid = left + (right-left)/2;
                if(x>=0 && 1ll*nums2[mid]*x<=target || x<0 && 1ll*nums2[mid]*x > target){
                    left = mid+1;
                }
                else right = mid-1;
            }
            if(x>=0) sum += left;
            else sum += n2-left;
        }
        return sum;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        long long ans = 0;
        long long left = -1e10, right = 1e10;

        while(left<=right){
            long long mid = left + (right-left)/2;
            long long cnt = count(nums1, nums2, mid);
            if(cnt < k ){
                left = mid+1;
            }
            // else if(cnt==k){
            //     return mid;
            // }
            else right = mid-1;
        }
        return left;
    }
};