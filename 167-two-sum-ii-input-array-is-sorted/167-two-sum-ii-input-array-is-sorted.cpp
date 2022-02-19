class Solution {
        // TC: O(N logN)
        // SC: O(1)
public:
    vector<int> twoSum(vector<int>& arr, int target) {
            int n=arr.size();
            
            for(int i=0;i<n;i++)
            {
                    int find=target-arr[i];
                    
                    int l=i+1,r=n-1;
                    while(l<=r){
                            int mid=l+(r-l)/2;
                            if(arr[mid]<find){
                                    l=mid+1;  
                            }
                            else if(arr[mid]==find)return {i+1,mid+1};
                            else r=mid-1;
                    }
            }
        return {-1,-1};
    }
};