# define vi vector<int>
// TC : O(M*N log (M*N))
class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool isValid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        int m = moveTime.size(), n = moveTime[0].size();
        //  pq element denotes <time, cur_cell_x, cur_cell_y, prev_trans_time_for_changing_the_cell>
        priority_queue<vi, vector<vi>, greater<vi>>pq;
        vector<vector<int>>dist(m, vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        pq.push({0, 0, 0, 2 });

        while(!pq.empty()){
            vector<int>temp = pq.top();
            pq.pop();
            int d = temp[0], x = temp[1], y = temp[2], pt = temp[3];
            if(x==m-1 && y==n-1) return d;
            if(dist[x][y]!=d) continue;

            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(!isValid(nx, ny, m, n) || (dist[nx][ny] <= max(d, moveTime[nx][ny]) + (pt==1?2:1)) ) continue;
                dist[nx][ny] =  max(d, moveTime[nx][ny]) + (pt==1?2:1);
                pq.push({dist[nx][ny], nx, ny, (pt==1?2:1)});

            }
        }

        return -1;
        

    }
};