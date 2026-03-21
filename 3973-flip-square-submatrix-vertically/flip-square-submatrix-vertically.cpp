class Solution {
    // TC : O(K*K)
    void swap_vertically(vector<vector<int>>& grid, int x, int y, int k){
        int i = x, j = x+k-1;
        while(i<j){
            swap(grid[i][y], grid[j][y]);
            i++; j--;
        }
    }
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k){

        vector<vector<int>> res = grid;
        for(int j=y;j<y+k;j++){
            swap_vertically(res, x, j, k);
        }
        return res;
    }
};