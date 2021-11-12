class Solution {
public:
        vector<vector<string>>ans;
        vector<pair<int,int>>queens_pos;
        void push_answer(int n){
                vector<string>temp;
                string s;
                for(int i=0;i<n;i++)s+=".";
                for(int i=0;i<n;i++)temp.push_back(s);
                for(auto x:queens_pos){
                        temp[x.first][x.second]='Q';
                }
                ans.push_back(temp);
        }
        bool isAttacking(int x,int y,int n){
                for(auto pii:queens_pos){
                     int i= pii.first;
                        int j=pii.second;
                        if(i==x || j==y)return true;
                        for(int t=1;t<n;t++){
                        if((i+t==x || i-t==x) && (j+t==y || j-t==y))return true;
                        }                   
                }
                return false;
        }
        void backtrack(int row,int n){
                if(row==n){
                       push_answer( n);
                }
                for(int i=0;i<n;i++){
                        if(!isAttacking(row,i,n)){
                                queens_pos.push_back({row,i});
                                backtrack(row+1,n);
                                queens_pos.pop_back();
                        }
                }
        }
     vector<vector<string>> solveNQueens(int n) {
      
        backtrack(0,n);
           
     return ans;       
    }
};