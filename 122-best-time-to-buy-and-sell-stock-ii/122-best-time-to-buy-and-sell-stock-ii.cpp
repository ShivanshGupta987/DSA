class Solution {
public:
        // TC: O(N)
        // SC:O(1)
        // Valley - Peak approach
    int maxProfit(vector<int>& prices) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int max_profit=0;
            for(int i=1;i<prices.size();i++){
                 if(prices[i]<prices[i-1])continue;  
                 max_profit+=(prices[i]-prices[i-1]);
            }
            return max_profit;
    }
};