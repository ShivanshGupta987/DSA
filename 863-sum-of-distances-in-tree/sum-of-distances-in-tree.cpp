class Solution {
    // TC : O(N)
    // SC : O(N)
    int subtree_sum(vector<vector<int>>& adj, vector<int>& node_cnt, int par, int u){
        int sum = 0;
        for(auto & v : adj[u]){
            if(v==par) continue;
            sum += subtree_sum(adj, node_cnt, u, v);
            sum += node_cnt[v];
            node_cnt[u] += node_cnt[v];
        }
        return sum;
    }
    void dfs(vector<vector<int>>& adj, vector<int>& node_cnt, vector<int>& ans, int u, int par, int n){
        for(auto & v : adj[u]){
            if(v==par) continue;
            ans[v] = ans[u] + n - 2*node_cnt[v];
            dfs(adj, node_cnt, ans, v, u, n);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>node_cnt(n,1);
        vector<vector<int>>adj(n);
        vector<int>ans(n);
        for(auto & edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans[0] = subtree_sum(adj, node_cnt, -1, 0);
        dfs(adj, node_cnt, ans, 0, -1, n);
        return ans;
    }
};