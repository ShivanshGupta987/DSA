
// TC : O(N log N)
// SC : O(N)

class Solution {
typedef unsigned long long int ull;
int N;
multiset<ull,greater<ull>>ms;
vector<vector<int>>graph;
int ans = 0; // no. of nodes with max score
public:
    int countHighestScoreNodes(vector<int>& parents) {
        
            ans = 1;
            N = parents.size();
            graph = vector<vector<int>>(N);
            for(int i=1;i<N;i++){
                    graph[i].push_back(parents[i]);
                    graph[parents[i]].push_back(i);
            }
            dfs(0,-1);
            ans = ms.count(*ms.begin());
            return ans;
    }
        
    int dfs(int node, int parent){
            
            int size = 1;
            ull product = 1;
            for(int child:graph[node]){
                    if(child!=parent){
                            int child_size = dfs(child,node);
                            size += child_size;
                            product*= child_size;
                    }
            }
            if(node!=0) product*= (N-size);
            ms.insert(product);
            
            return size;
    }

        
};