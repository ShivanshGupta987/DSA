class Solution {
    // TC : O(26*(V+E))
    // SC : O(V)
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(auto & edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        vector<vector<int>>dp(n, vector<int>(26));
        
        queue<int>q;

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                dp[i][colors[i]-'a'] = 1;
                q.push(i);
            }
        }
        
        
        int seen = 0;
        
        int ans = 1;
        while(q.size()){
            seen++;
            int u = q.front();
            q.pop();
            for(auto & v : adj[u]){
                if(--indeg[v]==0){
                    q.push(v);
                }
                for(int color=0;color<26;color++){
                    dp[v][color] = max(dp[v][color], dp[u][color] + (color==(colors[v]-'a')));
                    ans = max(ans, dp[v][color]);
                }
                
            }
            
        }

        return seen<n?-1:ans;
    }
};