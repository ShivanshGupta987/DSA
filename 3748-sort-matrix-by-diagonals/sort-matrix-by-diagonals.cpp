class Solution {
    // TC : O(N*N*N*log N)
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int row=0;row<n;row++){
            int x = row, y = 0;
            vector<int>temp;
            while(x<n && y<n){
                temp.push_back(grid[x][y]);
                y++;
                x++;
            }
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());
            x = row, y = 0;
            while(x<n && y<n){
                grid[x][y] = temp[y];
                y++;
                x++;
            }
        }
        for(int col=1;col<n;col++){
            int x = 0, y = col;
            vector<int>temp;
            while(x<n && y<n){
                temp.push_back(grid[x][y]);
                y++;
                x++;
            }
            sort(temp.begin(), temp.end());

            x = 0, y = col;
            while(x<n && y<n){
                grid[x][y] = temp[x];
                y++;
                x++;
            }
        }

        return grid;
    }
};