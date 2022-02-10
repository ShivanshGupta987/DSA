class Solution {
        
        vector<vector<string>> res;
        bool isAttacking(unordered_map<int,int>& mp, int x, int y){
        
                for(int t=1;t<=x;t++){
                        auto it =mp.find(x-t);
   if(it!=mp.end() && (it->second==y || it->second==y-t || it->second==y+t))return true;                  
                }
      return false;
        }
       void push_answer(unordered_map<int,int>&mp,int n){
               vector<string>board(n,string(n,'.'));
               for(auto &[x,y]:mp){
                       board[x][y]='Q';
               }
               res.push_back(board);
       }
        void generatePositions(int n,int row,unordered_map<int,int>& mp){
                if(row==n){push_answer(mp,n);return;}
                
                for(int i=0;i<n;i++){
                        
                      mp.insert({row,i});
                        
                      if(!isAttacking(mp,row,i)){
                              generatePositions(n,row+1,mp);
                      }  
                      mp.erase(row);
                }
                
        }
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_map<int,int>mp;   
        generatePositions(n,0,mp);
        return res;
    }
};