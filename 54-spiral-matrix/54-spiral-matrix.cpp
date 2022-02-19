class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            vector<int>res;
            vector<vector<bool>>isVisited(m,vector<bool>(n,false));
            int i=0,j=0;
         
            while(true){
                   
            if(j<n && !isVisited[i][j])
            {
                 while(j<n && !isVisited[i][j])
                 {
                         res.push_back(matrix[i][j]);
                         isVisited[i][j]=true;
                         j++;
                 } 
                    j--;
            }
            else break;
                    
                    i++;
                  while(i<m && !isVisited[i][j]){
                          res.push_back(matrix[i][j]);
                          isVisited[i][j]=true;
                          i++;
                  }
                    i--;
                    
                    j--;
                    while(j>=0 && !isVisited[i][j]){
                          res.push_back(matrix[i][j]);
                            isVisited[i][j]=true;
                            j--;
                    }
                    j++;
                   
                    i--;
                    while(i>=0 && !isVisited[i][j]){
                            res.push_back(matrix[i][j]);
                            isVisited[i][j]=true;
                            i--;
                    }
                    i++;
                    
                    j++;
            }
            return res;
          
    }
};