class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int dp[prices.size()+1 ][5];
        reverse(prices.begin(),prices.end());
        
        for(int day = 0; day<=prices.size(); day++){
            
            for(int transactionsDone = 0;transactionsDone <= 4;transactionsDone++){
                
                int &ans = dp[day][transactionsDone];
                
                if(day ==0){
                    ans = 0;
                }else if(transactionsDone == 0){
                    ans = 0;
                }else{
                    
                    // choice 1
                    // no transaction today
                    int ans1 = dp[day-1][transactionsDone];
                    
                    // choice 2
                    // doing the possible transaction today     
                    int ans2 = 0;
                    bool buy = (transactionsDone % 2 == 0);

                    if(buy == true){ // buy
                        ans2 = -prices[day-1] + dp[day - 1][transactionsDone - 1];
                    }else{ // sell
                        ans2 = prices[day-1] + dp[day - 1][transactionsDone - 1];
                    }

                    ans = max(ans1, ans2);

                }
                
            }
        }
            
//         for(int day = (int) prices.size();day >= 0;day--){
//             for(int transactionsLeft = 0;transactionsLeft <= 4;transactionsLeft++){
//                 cout<<dp[day][transactionsLeft]<<" ";
//             }
//                 cout<<endl;
//         }
            
        return dp[prices.size()][4];
    }
};