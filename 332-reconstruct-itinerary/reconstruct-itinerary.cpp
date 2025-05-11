class Solution {
    // TC : O(E log E)
    // where E : no. of edges
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
            unordered_map<string, multiset<string>>adj;

            for(auto & ticket : tickets){
                adj[ticket[0]].insert(ticket[1]);
            }

            stack<string>st;
            vector<string>res;
            st.push("JFK");
            while(!st.empty()){
                string cur_airport = st.top();
                
                if(adj[cur_airport].size() == 0 ){
                    res.push_back(cur_airport);
                    st.pop();
                }
                else{
                    auto next_airport_itr = adj[cur_airport].begin();
                    st.push(*next_airport_itr);
                    adj[cur_airport].erase(next_airport_itr);
                }
            }
            
            reverse(res.begin(), res.end());
            return res;
    }
};