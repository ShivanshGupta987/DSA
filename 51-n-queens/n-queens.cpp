class Solution {
    // TC : O(N^N)
    vector<vector<string>>res;
    int dx[8] = {1, -1, -1, 1, 1, 0, -1, 0};
    int dy[8] = {1, -1, 1, -1, 0, -1, 0, 1};
    bool isValid(int x, int y, int n){
        return x>=0 && x<n && y<n && y>=0;
    }
    bool isValidConfig(int row, int col, int n, vector<string>& board){
        for(int k=0;k<8;k++){
            int x = row, y = col;
            while(isValid(x, y, n)){
                if(board[x][y]=='Q') return false;
                x += dx[k];
                y += dy[k];
            }   
        }
        return true;
    }
    void backtrack(int row, int n, vector<string>& board){
        if(row==n){
            res.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValidConfig(row, col, n, board)){
                board[row][col] =  'Q';
                backtrack(row+1, n, board); 
                board[row][col] = '.';
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n, '.'));
        backtrack(0,n,board);
        return res;
    }
};