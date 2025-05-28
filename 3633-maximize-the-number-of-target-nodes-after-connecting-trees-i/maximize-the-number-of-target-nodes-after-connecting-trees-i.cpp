class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                            vector<vector<int>>& edges2, int k) {
    // given two trees : Tree1 with n nodes
    //                   Tree2 with m nodes

    // now target nodes for any node x is all those nodes whose path to x
    // contains edges <= k.
    //  each node is target node for itself.

    // now iterate i over n, and for each i output no of target nodes for
    // node i if on each iteration you have to connect one node from Tree2.
    //  and after each iteration the connected edge will be dissipated.

    // basically if i connect any node with node I then i have a subproblem
    // to find out the optimal node in Tree2 which has max. target nodes for
    // newK = k-1 in tree2. and add that to my Tree1 output for targets each time. and
    // BOOM!! result.

    int n = (int)edges1.size() + 1;
    int m = (int)edges2.size() + 1;
    vector<int> answer(n);

    vector<vector<int>> adj1(n), adj2(m);
    for (auto it : edges1) {
        adj1[it[0]].push_back(it[1]);
        adj1[it[1]].push_back(it[0]);
    }
    for (auto it : edges2) {
        adj2[it[0]].push_back(it[1]);
        adj2[it[1]].push_back(it[0]);
    }

    auto dfs = [&](auto&& self, int node, int parent,
                    vector<vector<int>>& adj, int dist, int target) -> int {
        if (dist > target)
            return 0;
        // visited[node]=1; // don't need array just parent var would suffice
        int cnt = 1;
        for (auto it : adj[node]) {
            if (it != parent) {
                cnt += self(self, it, node, adj, dist + 1, target);
            }
        }
        return cnt;
    };

    int maxiTree2 = 0;
    for (int i = 0; i < m; i++) {
        // vector<int> visited(m,0); // no need we will do it by sending
        // parent node due to tree's property of acyclic
        int targets = dfs(dfs, i, -1, adj2, 0, k - 1);
        // cout<<i<<" "<<targets<<endl;
        maxiTree2 = max(maxiTree2, targets);
    }

    for (int i = 0; i < n; i++) {
        int target = dfs(dfs, i, -1, adj1, 0, k);
        answer[i] = target + maxiTree2;
    }
    return answer;
}
};