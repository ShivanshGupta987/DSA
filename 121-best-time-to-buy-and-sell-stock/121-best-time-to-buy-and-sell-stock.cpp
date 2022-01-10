class Solution {
public:
    int maxProfit(vector<int>& prices) {
            // TC:O(N)
            int minn=prices[0];
            int max_profit=0;
            for(int i=1;i<prices.size();i++){
                if(minn>prices[i])minn=prices[i];
                 max_profit=max(max_profit,prices[i]-minn);
            }
            return max_profit;
        
    }
};