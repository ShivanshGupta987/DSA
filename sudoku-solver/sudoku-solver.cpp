class Solution {
public:
        bool IsSafe(int x,int y,char n,int N,vector<vector<char>>& board){
                for(int i=0;i<N;i++){
                        if(board[i][y]==n || board[x][i]==n)return false;
                }
                int sq=sqrt(N);
                int grid_x=x-x%sq;
                int grid_y=y-y%sq;
                
                for(int i=0;i<sq;i++){
                        for(int j=0;j<sq;j++){
                                if(board[i+grid_x][j+grid_y]==n)return false;
                        }
                }
                
                return true;
        }
        bool backtrack(vector<vector<char>>& board,vector<pair<int,int>>&empty_pos,int N){
                if(empty_pos.size()==0)return true;
                int x=empty_pos[empty_pos.size()-1].first;
                int y=empty_pos[empty_pos.size()-1].second;
                for(char n='1';n<=N+'0';n++){
                if(IsSafe(x,y,n,N,board)){
                        board[x][y]=n;
                        empty_pos.pop_back();
                        if(backtrack(board,empty_pos,N))return true;
                        board[x][y]='.';
                        empty_pos.push_back({x,y});
                }
                }
                return false;
        }
        
    void solveSudoku(vector<vector<char>>& board) {
        int N= board.size();
           // cout<<board.size();
            vector<pair<int,int>>empty_pos;
            for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                       if(board[i][j]=='.')empty_pos.push_back({i,j});     
                    }
            }
           
          backtrack(board,empty_pos,N);
            
    }
};