class Solution {
    // TC : O(N + q log q)
    // WHERE N : SIZE OF NUMS
    // q : SIZE OF QUERIES
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        
        sort(queries.begin(), queries.end());
        // (max heap) storing ending points of queries whose starting times are
        // smaller than current time index
        priority_queue<int>available; 

        // (min heap) taking ending points from the max heap(available) and adding 
        // ending points while they are greater than or equal to current time index 
        priority_queue<int,vector<int>, greater<int>> assigned;
        
        int count = 0;
        int n = nums.size();
        for(int time=0, k=0; time < nums.size(); time++){
            
            // remove outdated queries
            while(!assigned.empty() && assigned.top() < time){
                assigned.pop();
            }

            // add end time of candidate queries into available max heap
            while(k<queries.size() && queries[k][0] <= time ){
                available.push(queries[k++][1]);
            }

            // greedily assigning queries
            while(assigned.size() < nums[time] && !available.empty()
             && available.top() >= time){
                assigned.push(available.top());
                available.pop();
                count++;
            }

            if(assigned.size() < nums[time]) return -1;
        }
        return queries.size() - count;
    }
};