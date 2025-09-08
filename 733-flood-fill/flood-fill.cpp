class Solution {
    // TC : O(M*N*4)
    bool isValid(int x, int y, int m, int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    void dfs(vector<vector<int>>& grid, int x, int y, int starting_color, int color){
        int m = grid.size(), n = grid[0].size();
        grid[x][y] = color;
        for(int k=0;k<4;k++){
            int nx = x+dx[k], ny = y+dy[k];
            if(isValid(nx, ny, m, n) && grid[nx][ny]==starting_color){
               
                dfs(grid, nx, ny, starting_color, color);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int m = grid.size(), n = grid[0].size();
        if(color==grid[sr][sc]) return grid;
        dfs(grid, sr, sc, grid[sr][sc], color);

        return grid;
    }
};