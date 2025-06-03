class Solution {
    // TC : O(N)
    // SC : O(N)
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        queue<int>q;
        vector<int>box_found(n, 0), key_found(n, 0), box_pushed(n, 0);
        int cnt = 0;
        
        for(auto & box : initialBoxes){
            if(status[box] == 1){
                q.push(box);
                key_found[box] = 1;
                box_pushed[box] = 1;
            }
            box_found[box] = 1;
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            cnt += candies[cur];

            for(auto & box : keys[cur]){
                key_found[box] = 1;
                if(box_found[box] && !box_pushed[box]){
                    q.push(box);
                    box_pushed[box] = 1;
                } 
            }

            for(auto & box : containedBoxes[cur]){
                box_found[box] = 1;
                if((key_found[box] || status[box]) && !box_pushed[box]){
                    q.push(box);
                    box_pushed[box] = 1;
                }
            }
        }
        return cnt;
    }
};