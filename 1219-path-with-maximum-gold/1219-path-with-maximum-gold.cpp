class Solution {
        int max_profit;
        int m,n;
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        max_profit=0;
         m=grid.size();
         n=grid[0].size();
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                            rec(i,j,0,grid);
                    }
            }
            return max_profit;
            
    }
        private:
        void rec(int i,int j,int profit,vector<vector<int>>& grid){
           if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)return;     
          profit+=grid[i][j];
              int x=grid[i][j];
                grid[i][j]=0;

          rec(i-1,j,profit,grid);
          rec(i+1,j,profit,grid);
                rec(i,j-1,profit,grid);
                rec(i,j+1,profit,grid);
                grid[i][j]=x;
                
                max_profit=max(max_profit,profit);
        }
};