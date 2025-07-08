class Solution {
    vector<vector<int>>dp;
    int res;
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[0] < b[0] || (a[0]==b[0] && a[1] < b[1]);
    }
    int solve(vector<vector<int>>& events, int i, int event_cnt, int k){
        int n = events.size();
        if(event_cnt >= k || i>=n) return 0;
        if(dp[event_cnt][i] != -1) return dp[event_cnt][i];
        int ans = 0;
        int left = 0, right = n;
        int idx = -1;
        while(left<right){
            int mid = (left+right)/2;
            if(events[mid][0] <= events[i][1]){
                left = mid+1;
            }
            else right = mid;
        }
        idx = left;
        // take it 
        ans = max(ans, solve(events, idx, event_cnt+1, k) + events[i][2]);
        
        // don't take it
        ans = max(ans, solve(events, i+1, event_cnt, k));
        this->res = max(this->res, ans);
        return dp[event_cnt][i] = ans;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), comp);
        int n = events.size();
        dp.resize(k+1, vector<int>(n,-1));
        this->res = 0;
        solve(events, 0, 0, k);
        return res;
    }
};