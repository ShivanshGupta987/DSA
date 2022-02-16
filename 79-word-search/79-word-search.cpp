class Solution {
        // TC: (3^N)
        // SC: O(N)
        // N -> word.size()
        bool helper(vector<vector<char>>& board, string& word, int i, int x, int y){
                if(i==word.size())return true;
                if(x<0 || x>=board.size() || y<0 ||                                              y>=board[0].size())return false;
                if(word[i]!=board[x][y])return false;
                
                int dx[]={-1,1,0,0};
                int dy[]={0,0,1,-1};
                
                char temp=board[x][y];
                board[x][y]='.';
                for(int j=0;j<4;j++){       
                     if(helper(board, word,i+1,x+dx[j],y+dy[j]))return true; 
                }
                board[x][y]=temp;
                
                return false; 
        }
public:
    bool exist(vector<vector<char>>& board, string word) {
       for(int i=0;i<board.size();i++){
               for(int j=0;j<board[0].size();j++){
                       if(board[i][j]==word[0] &&                                                   helper(board,word,0,i,j))return true;
               }
       }
              return false;
    }
      
};