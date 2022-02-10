class Solution {
        private: bool winningStates(vector<string>&board,int xs,int os){
                int count =0;
                char fc;
                int xw=0,ow=0;
                for(int i=0;i<3;i++){
                        char c=board[i][0];
                        
                        for(int j=1;j<3;j++){
                           if(c==' ')break;
                           if(c!=board[i][j] ) break;
                                c=board[i][j];
                           if(j==2){
                                   count++;fc=c;
                                   if(c=='X')xw++;
                                   else ow++;
                           }
                        }
                }
                
                for(int i=0;i<3;i++){
                        char c=board[0][i];
                        
                        for(int j=1;j<3;j++){
                           if(c==' ')break;
                           if(c!=board[j][i] ) break;
                                c=board[j][i];
                           if(j==2){
                                   count++;fc=c;
                                   if(c=='X')xw++;
                                   else ow++;
                           }
                        }
                        
                }
                char c=board[0][0];
                for(int i=0;i<3;i++){
                        
                           if(c==' ')break;
                           if(c!=board[i][i] ) break;
                           c=board[i][i];
                           if(i==2){
                                   count++;fc=c;
                                   if(c=='X')xw++;
                                   else ow++;
                           }
                }
                c=board[0][2];
                for(int i=0;i<=2;i++){
                        
                           if(c==' ')break;
                           if(c!=board[i][2-i] ) break;
                           c=board[i][2-i];
                           if(i==2){
                                   count++;fc=c;
                                   if(c=='X')xw++;
                                   else ow++;
                           }
                }
               
                if(count==0)return true;
                if(count==1){
                        if(xs==os && fc=='X')return false;
                        else if(xs+os==9 && fc=='O')return false;
                        else return true;
                }
                if(count==2){
                        if(!xw || !ow)return true;
                }
                return false;
                
        }
public:
    bool validTicTacToe(vector<string>& board) {
      int xs=0, os=0;
            for(auto x: board)
                    for(auto y: x) 
                            y=='X'?xs++:(y=='O'?os++:0);
         if(xs<os || xs>os+1)  return false;
            
          return winningStates(board,xs,os);
           
    }
};