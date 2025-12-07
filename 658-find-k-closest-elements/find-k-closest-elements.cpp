class Solution {
    // ------------- BINARY SEARCH -------------
    // TC : O(log N)
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // binary search for range [0, n-k] for the finding the range 
        // [left, left+k-1] while left can take the above defined range [0, n-k]
        int left = 0, right = n-k;

        while(left<right){
            int mid = (left+right)/2;
            // predicate(mid) == 0 then lies in left
            if(x-arr[mid] > arr[mid+k]-x){
                left = mid+1;
            }
            else right = mid;
        }
        return vector<int>(arr.begin()+left, arr.begin()+left+k);

    }
};



class Solution1 {
    // ------------- TWO POINTER SOLUTION ------------
    // TC : O(N)
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n-1;
        while(r-l+1>k){
            if(abs(arr[l]-x) <= abs(arr[r]-x)){
                r--;
            }
            else l++;
        }
        return vector<int>(arr.begin()+l, arr.begin()+r+1);

    }
};