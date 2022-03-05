class Solution {
        // TC : O(N log N)
        // SC : O(N)
        #define vi vector<int>
    bool dontOverlap(vi a, vi b){ return a[1]<=b[0];}
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
            int n= profit.size();
            for(int i=0;i<n;i++){
                    jobs.push_back({startTime[i] ,endTime[i] ,profit[i] });
            }
            
           sort(jobs.begin(),jobs.end(),[](const vi a, const vi b){return a[1]<b[1];});
            
          
         map<int,int>dp{{0,0}};
         for(int i=0;i<n;i++){
         int cur_profit = prev(dp.upper_bound(jobs[i][0]))->second + jobs[i][2];
                    if(cur_profit > dp.rbegin()->second) dp[jobs[i][1]] = cur_profit;
            }
            return dp.rbegin()->second;
    }
};