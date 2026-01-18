class Solution {
    vector<vector<int>> hpsum; // row prefix sum
    vector<vector<int>> vpsum; // column prefix sum

    // brx, bry are 1-based EXCLUSIVE bottom-right corner
    bool isMagicSquare(int brx, int bry, int side, vector<vector<int>>& grid) {
        // target sum from first row
        int target = hpsum[brx - side + 1][bry] - hpsum[brx - side + 1][bry - side];

        // check all rows
        for (int r = brx - side + 1; r <= brx; r++) {
            int rowSum = hpsum[r][bry] - hpsum[r][bry - side];
            if (rowSum != target) return false;
        }

        // check all columns
        for (int c = bry - side + 1; c <= bry; c++) {
            int colSum = vpsum[brx][c] - vpsum[brx - side][c];
            if (colSum != target) return false;
        }

        // check diagonals (convert to 0-based grid)
        int d1 = 0, d2 = 0;
        for (int k = 0; k < side; k++) {
            d1 += grid[brx - 1 - k][bry - 1 - k];
            d2 += grid[brx - 1 - k][bry - side + k];
        }

        return d1 == target && d2 == target;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        hpsum.assign(m + 1, vector<int>(n + 1, 0));
        vpsum.assign(m + 1, vector<int>(n + 1, 0));

        // build prefix sums (1-based)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hpsum[i + 1][j + 1] = hpsum[i + 1][j] + grid[i][j];
                vpsum[i + 1][j + 1] = vpsum[i][j + 1] + grid[i][j];
            }
        }

        // try largest side first
        for (int side = min(m, n); side >= 2; side--) {
            for (int x = side; x <= m; x++) {
                for (int y = side; y <= n; y++) {
                    if (isMagicSquare(x, y, side, grid))
                        return side;
                }
            }
        }

        return 1;
    }
};
