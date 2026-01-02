class Solution {
    // TC : O(N)
public:
    int repeatedNTimes(vector<int>& arr) {
        int n = arr.size();
        
        for(int i=0;i<n-3;i++){
            if(arr[i]==arr[i+2] || arr[i]==arr[i+3] || arr[i]==arr[i+1]){
                return arr[i];
            }
            else if( arr[i+1]==arr[i+2] || arr[i+1]==arr[i+3] ){
                return arr[i+1];
            }
            else if(arr[i+2]==arr[i+3]) return arr[i+2];
        }
        return arr[0];
    }
};