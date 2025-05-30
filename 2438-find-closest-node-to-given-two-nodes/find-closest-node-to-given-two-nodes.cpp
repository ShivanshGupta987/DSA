class Solution {
    // TC : O(N)
    const int INF = INT_MAX;
    void dfs(vector<int>& edges, vector<int>& vis, vector<int>& dist, int u, int d){
        vis[u] = true;
        dist[u] = d;
        int child = edges[u];
        if(child !=-1 && !vis[child]) dfs(edges, vis, dist, child, d+1);
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n, INF), dist2(n, INF);
        vector<int>vis1(n, false), vis2(n, false);
        
        dfs(edges, vis1, dist1, node1, 0);
        dfs(edges, vis2, dist2, node2, 0);
        int min_d = INF;
        int ind = -1;
        for(int i=0;i<n;i++){
            if(min_d > max(dist1[i], dist2[i])){
                min_d = max(dist1[i], dist2[i]);
                ind = i;
            }
        }
        return ind;
    }
};