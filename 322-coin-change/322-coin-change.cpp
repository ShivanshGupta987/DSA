class Solution {
        // TC : O(S*N)
        // SC : O(S)
        // S -> AMOUNT
        // N -> NO. OF COINS
private:
    int helper(vector<int>& coins,vector<int>& amt,int target){
                if(target==0)return 0;
                if(target<0)return -1;
                
                if(amt[target]!=0)return amt[target];
                 
                int min_cost = INT_MAX;
                for(auto coin : coins){
                   int res = helper(coins, amt, target-coin);
                   if(res!=-1)min_cost=min(min_cost,res+1);
                }
            return amt[target]= min_cost== INT_MAX ? -1 : min_cost;
        }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>amt(amount+1);
            return helper(coins, amt, amount);
            
    }
};














//class Solution {
//         // BRUTE FORCE
//         // TLE
//         // EXPONENTIAL TC
//     private :  
//         int helper(vector<int>& coins, int target, int i){
//                 if(target==0)return 0;
//                 if(target<0 || coins.size()==i)return -1;
                
//                 int max_coins = target/coins[i];
//                 int min_cost=INT_MAX; // minimum required coins
//                 for(int x=0; x<= max_coins ; x++){
//                         int ans = helper(coins, target-x*coins[i], i+1);
//                         if(ans!=-1) min_cost=min(min_cost,x+ans);
//                 }
//                 return min_cost==INT_MAX? -1 : min_cost;
//         }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//      return  helper(coins,amount,0);   
//     }
// };