class Solution {
    // TC : O(N^3)
    // SC : O(1)
    // N : SIZE OF THE ARRAY
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(arr[j]-arr[i]) > a) continue;
                for(int k=j+1;k<n;k++){
                    if(abs(arr[k] - arr[j]) >  b)continue;
                    if(abs(arr[k]-arr[i]) <= c) cnt++;
                }
            }
        }
        return cnt;

    }
};