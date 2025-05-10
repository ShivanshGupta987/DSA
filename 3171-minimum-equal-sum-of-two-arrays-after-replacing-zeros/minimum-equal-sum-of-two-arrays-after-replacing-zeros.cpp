class Solution {
    // TC : O(N)
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
       
        long long sum1 = 0, sum2 = 0, zc1 = 0, zc2 = 0;
        for(int i=0;i<nums1.size();i++){
            sum1 += nums1[i];
            if(nums1[i]==0) zc1++;
        }
        for(int i=0;i<nums2.size();i++){
            sum2 += nums2[i];
            if(nums2[i]==0) zc2++;
        }
        if(zc1 && zc2) return max(sum1+zc1, sum2+zc2);
        if(zc1==0 && zc2==0) return sum1==sum2? sum1 : -1;
        if(zc1==0){
            if(sum1<=sum2) return -1;
            else if(zc2 > sum1-sum2) return -1;
            else return sum1;
        }
        if(zc2==0){
            if(sum2<=sum1) return -1;
            else if(zc1 > sum2-sum1) return -1;
            else return sum2;
        }
        
        return -1;
        
    }
};