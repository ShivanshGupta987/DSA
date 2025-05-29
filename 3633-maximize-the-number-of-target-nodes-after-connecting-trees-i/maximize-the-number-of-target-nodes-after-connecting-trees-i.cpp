class Solution {
    // TC : O(K*(N+M))
    // SC : O(N+M)
    int get_count(vector<vector<int>>& adj, int u, int par, int dist, int target){
        if(dist > target) return 0;
        int cnt = 1;
        for(auto & v : adj[u]){
            if(v==par) continue;
            cnt += get_count(adj, v, u, dist+1, target);
        }
        return cnt;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>>adj1(n); 
        vector<vector<int>>adj2(m);

        for(auto & edge : edges1){
            int u = edge[0], v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        } 
        for(auto & edge : edges2){
            int u = edge[0], v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        } 
        int mx_cnt2 = 0;
        for(int i=0;i<m;i++){
            mx_cnt2 = max(mx_cnt2, get_count(adj2, i,-1,0, k-1));
        }

        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i] = get_count(adj1, i, -1, 0, k) + mx_cnt2;
        }
        return res;


        
    }
};