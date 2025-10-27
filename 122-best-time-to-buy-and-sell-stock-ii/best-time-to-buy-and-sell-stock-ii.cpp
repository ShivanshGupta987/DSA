class Solution {
    // TC : O(N)
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int total_profit = 0;
        for(int i=0;i<n;i++){
            int j = i+1;
            while(j<n && arr[j]>arr[j-1]){
                j++;
            }
            total_profit += arr[j-1]-arr[i];
            i = j-1;
        }
        return total_profit;
    }
};