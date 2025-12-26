class Solution {
    // TC : O(N)
    // SC : O(1)
public:
    int bestClosingTime(string customers) {
        int hr=0, total_profit=0;
        int cur_profit = 0;
        for(int i=0;customers[i];i++){
            if(customers[i]=='Y'){
                cur_profit++;
            }
            else cur_profit--;
            if(cur_profit>total_profit){
                hr = i+1;
                total_profit = cur_profit;
            }
        }
        return hr;
    }
};