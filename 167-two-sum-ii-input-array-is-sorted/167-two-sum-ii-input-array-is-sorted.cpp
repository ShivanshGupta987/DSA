class Solution {
        // TC : O(N)  // N-> arr.size()
        // SC: O(1)
public:
    vector<int> twoSum(vector<int>& arr, int target) {
         int n=arr.size();
            int l=0,r=n-1;
            while(l<r){
               if(arr[l]+arr[r]==target)return {l+1,r+1};
               else if(arr[l]+arr[r]>target)r--;
                    else l++;
            }
            return {};
    }
};