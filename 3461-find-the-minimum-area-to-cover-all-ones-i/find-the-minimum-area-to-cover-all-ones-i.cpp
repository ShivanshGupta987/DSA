class Solution {
    // TC : O(M*N)
    // SC : O(1)
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x1 = n, x2 = -1, y1 = m, y2 = -1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    x1 = min(x1, j);
                    x2 = max(x2, j);
                    y1 = min(y1, i);
                    y2 = max(y2, i);
                }
            }
        }
        return (x2-x1+1)*(y2-y1+1);
    }
};