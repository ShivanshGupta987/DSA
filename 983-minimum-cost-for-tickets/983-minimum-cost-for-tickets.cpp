class Solution {
        // TC : O(365)

    vector<int>cost;
    unordered_set<int>day;
        
    int helper(int i,vector<int>& memo){
            if(i>365) return 0;
            if(memo[i]!=-1) return memo[i];
            int ans;
            if(day.find(i)!=day.end()){
                    ans = min(helper(i+1,memo) + cost[0] , helper(i+7,memo) + cost[1]);
                    ans = min(ans,helper(i+30,memo)+cost[2]);
            }
            else ans = helper(i+1,memo);
            return memo[i]=ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         vector<int>memo(366,-1);  
         cost = costs;
         for(int i=0;i<days.size();i++)day.insert(days[i]);
         return helper(0,memo); 
    }
};