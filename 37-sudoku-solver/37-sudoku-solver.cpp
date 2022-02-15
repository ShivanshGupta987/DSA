class Solution {
       bool isValid(vector<vector<char>>&board,int i,int j,char c){
        int X=i-i%3, Y=j-j%3;
      
        for(int k=0;k<9;k++){
                if(c==board[i][k])return false;  // check row 
                if(c==board[k][j])return false;   // check column
        }
        
        for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                        if(c==board[x+X][y+Y])return false;
                }
        }
        return true;
}
        bool helper(vector<vector<char>>& board ,int i, int j){
              
                if(j==9)return helper(board,i+1,0);
                if(i==9 )return true;;
                if(board[i][j]!='.'){return helper(board,i,j+1);}
                for(int k=1;k<=9;k++){
                       
                       if(isValid(board,i,j,'0'+k)){
                               board[i][j]='0'+k;
                              if(helper(board,i,j+1))return true;
                               board[i][j]='.';
                       }
                }
                
                
            return false;    
        }
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};