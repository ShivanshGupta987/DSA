class Solution {
    // TC : O(M^3)
    // SC : O(M^2)
    // WHERE M : CUTS.SIZE()
    int dp[102][102];
    int INF = 1e9;
    int rec(int start, int end, vector<int>& cuts){
        if(dp[start][end]!=-1) return dp[start][end];
        if(start+1==end) return dp[start][end] = 0;
        int ans = INF;
        for(int mid = start+1; mid<end; mid++){
            ans = min(ans, (cuts[end]-cuts[start]) + rec(start, mid, cuts) + rec(mid, end, cuts));
        }
        return dp[start][end] = ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof dp);
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return rec(0, cuts.size()-1, cuts);
    }
};