class Solution {
    // TC : O(N+M)
// ---------- IDEA --------
// start dfs from root node to color node at even distance by white and at odd distance
// by black so the total no. of nodes at even distance will share the same color 
// while the total no. of nodes at odd distance will share the different color

int dfs(const vector<vector<int>>& adj, vector<int>& color, int u, int par, int white){
    int cnt = white;
    color[u] = white;
    for(auto & v : adj[u]){
        if(v==par)continue;
        cnt += dfs(adj, color, v, u, 1-white);
    }
    return cnt;
}

vector<int> build(const vector<vector<int>>& edges, vector<int>& color){
    int n = edges.size() + 1;
    vector<vector<int>>adj(n);
    for(auto & edge : edges){
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int white = dfs(adj, color, 0, -1, 1);
    int black = n - white;
    return {black, white};
}

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<int>color1(n), color2(m);
        vector<int>cnt1 =  build(edges1, color1);
        vector<int>cnt2 =  build(edges2, color2);
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i] = cnt1[color1[i]] + max(cnt2[0], cnt2[1]);
        }
        return res;

    }
};