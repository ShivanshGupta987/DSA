
// TC : O(N)
// SC : O(N)
class Solution {
int N;
vector<int> ans; /* after execution of preprocessing function , ans[i] contains subtree sum of the subtree having root node `i`
--------------------------
after execution of dfs function, ans[i] contains the distance b/w the ith node in the tree and all other nodes
*/      
vector<int> count; // count[i] contains the no. of nodes in the subtree of root node `i`
vector<vector<int>> graph; // adjacency list
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
         
            count = vector<int>(n,1);
            ans = vector<int>(n);
            graph = vector<vector<int>>(n);
            N = n;
            for(int i=0;i<edges.size();i++){
                    graph[edges[i][0]].push_back(edges[i][1]);
                    graph[edges[i][1]].push_back(edges[i][0]);
            }
            
            
            preprocessing_dfs(0,-1);
            dfs(0,-1);
            return ans;
        
    }
        
void preprocessing_dfs(int node, int parent){
        
        for(auto child : graph[node]){
                if(child!=parent){
                        preprocessing_dfs(child,node);
                        count[node]+= count[child];
                        ans[node]+= ans[child] + count[child];
                }
        }
}
        
void dfs(int node, int parent){
        
        for(auto child : graph[node]){
                if(child!=parent){
                        ans[child] = ans[node] - count[child] + N - count[child];
                        dfs(child,node);
                }
        }
}
};