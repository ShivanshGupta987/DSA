class Solution {
        
        // TC : O(N)
public:
    int checkWays(vector<vector<int>>& pairs) {
        
            // bitset to record nodes present in pair
            // max. no. of nodes = 500
            bitset<501>visited;
            int max_node = 0;
            for(auto & p : pairs)
            {
                    visited[p[0]]=1;
                    visited[p[1]]=1;
                    max_node = max(max_node,max(p[0],p[1]));
            }
            
            // making graph (2-D matrix) from given pairs using bitset
            vector<bitset<501>>graph(max_node + 1);
            
            for(auto &p : pairs){
                    graph[p[0]][p[1]] = 1;
                    graph[p[1]][p[0]] = 1;
            }
            
            // all nodes connect to itself at least 
            int i=0;
            for(auto &b : graph){
                    b[i++]=1;
            }
            
            // root validation
            bool found = false;
            for(auto &b : graph){
                    if(b.count() == visited.count()){
                            found = true;
                            break;
                    }
            }
            if(!found) return 0;
            
            /* checking for the all the given pairs -
               adj-list of an element of the pair must cover adj-list of  another 
               element of the pair
            */
            
            bool many_sol = false;
            for(auto &p : pairs){
                    bool a = (graph[p[0]] | graph[p[1]] ) == graph[p[0]];
                    bool b = (graph[p[0]] | graph[p[1]] ) == graph[p[1]];
                    if(!a && !b) return 0;
                    if(a && b) many_sol = true; // implies nodes can be swapped hence there exist more than one solution
            }
            
            return many_sol?2:1;
            
            
    }
};



// // TC : O(N log N)
// class Solution {
// public:
//     int checkWays(vector<vector<int>>& pairs) {
        
//             // creating adjacency list considering that our graph is made                       up of pairs 
//             // here degree of node v => no. of pairs in which v is present
//             unordered_map<int,unordered_set<int>>adj;
            
//             for(int i=0;i<pairs.size();i++)
//             {
//                     adj[pairs[i][0]].insert(pairs[i][1]);
//                     adj[pairs[i][1]].insert(pairs[i][0]);
//             }
            
//             // making priority queue to record node along with its degree
//             priority_queue<pair<int,int>>pq;
            
//             for(auto &[node,neighbours]:adj)
//             {
//                     pq.push({neighbours.size(),node});
//             }
            
//             int total_nodes = pq.size();
//             int result = 1;
            
//             // keeps track of visited node and algorithm is designed in such a way 
//             // that visited nodes are always their ancestor or either childs of their 
//             // ancestor ( since priority queue firstly process the nodes with greater 
//             // degree)
//             unordered_set<int>visited;
            
//             // processes the node in decreasing order of their degree
//             while(!pq.empty())
//             {
//                     auto [degree, curr_node] = pq.top();
//                     pq.pop();
                    
//                 // Finding out the parent node with least degree
                
//                     int parent = -1;
//                     int parent_degree = INT_MAX;
//                     for(auto & neighbour : adj[curr_node])
//                     {
//                             if(visited.count(neighbour) && 
//                                adj[neighbour].size() < parent_degree && 
//                                adj[neighbour].size() >= degree)
//                             {
//                                     parent = neighbour;
//                                     parent_degree = adj[neighbour].size();
//                             }       
//                     }
                    
//                     visited.insert(curr_node);
//                     // checking whether the current node is parent or not
                    
//                     if(parent == -1)
//                     {
//                         // if parent doesn't exist
//                         if(degree != total_nodes-1) return 0;
//                         continue;
//                     }
                    
//                     // checking whether the parent's adj-List consists of all the nodes present in curr_node's adj-List
                    
//                     for(auto neighbour : adj[curr_node])
//                     {
//                             if(neighbour == parent ) continue;
//                             if(!adj[parent].count(neighbour)) return 0;
//                     }
                    
//                     /* check the special case of multiple trees
//                        the parent node and curr_node can be exchanged if they have 
//                        same degree */
                    
//                     if(degree == parent_degree) result = 2;
                    
                    
//             }
//          return result;       
//     }
// };