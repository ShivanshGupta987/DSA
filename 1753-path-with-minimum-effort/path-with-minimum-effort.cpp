class Solution { 
// TC : O(E log V) WHERE E = 4*M*N AND V = M*N
// SC : O(M*N)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool isValid(int x, int y, int n, int m){
    return x>=0 && y>=0 && x<n && y<m;
}
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int INF = 1e9;
        vector<vector<int>>dp(n, vector<int>(m, INF));
        // node<dist,x,y>
        priority_queue<vector<int>>pq;
        pq.push({0,0,0});
        dp[0][0] = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int d = temp[0], x = temp[1], y = temp[2]; 
            if(d != -dp[x][y]) continue;
            if(x==n-1 && y==m-1) return dp[x][y];
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(isValid(nx, ny, n, m) && dp[nx][ny] > abs(heights[x][y]-heights[nx][ny])){
                    int newEffort = max(dp[x][y], abs(heights[x][y] - heights[nx][ny]));
                    if (newEffort < dp[nx][ny]) {
                        dp[nx][ny] = newEffort;
                        pq.push({-newEffort, nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};