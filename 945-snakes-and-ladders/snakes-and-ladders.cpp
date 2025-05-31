#define pii pair<int,int> 
class Solution {
    // TC : O(N*N)
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<int>dist(n*n+1, -1);
        unordered_map<int, int>get_cell;
        
        int label = 1, i = n-1, j = 0;
        int forward = true;
        while(i>=0 && j>=0){
            get_cell[label++] = i*n + j;
            j += (forward?1:-1);
            if(j==n){
                i--, j = n-1;
                forward = false;
            }
            if(j<0){
                i--, j = 0;
                forward = true;
            }
        }
        
        dist[1] = 0;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int next = cur+1; next <= min(cur+6, n*n); next++){
                int cell = get_cell[next];
                int x = cell/n , y = cell%n;
                int destination = board[x][y]!=-1? board[x][y] : next;
                if(dist[destination] == -1){
                    dist[destination] = dist[cur] + 1;
                    q.push(destination);
                }
            }
        }

        return dist[n*n];
    }
};