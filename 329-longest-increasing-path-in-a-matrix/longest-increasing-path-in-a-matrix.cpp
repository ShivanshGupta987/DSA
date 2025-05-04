// --------------- TOPOLOGICAL SORING --------------
// IDEA : on creating the edge b/w the node having smaller value and adjacent node having
// having larger value, no cycle exist in the graph
// so topological sorting of the graph exist 
// hence we can apply kahn's topological sorting algorithm 
class Solution {
// TC : O(M*N)
// SC : O(M*N)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool isValid(int x, int y, int m, int n){
    return x>=0 && y>=0 && x<m && y<n;
}
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();

        vector<int>indeg(m*n);
        for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){
                for(int k=0; k<4; k++){
                    int new_x = x + dx[k];
                    int new_y = y + dy[k];
                    if(isValid(new_x, new_y, m, n) && mat[x][y] < mat[new_x][new_y]){
                        indeg[new_x*n + new_y]++;
                    }
                }
            }
        }

        queue<pair<int,int>>q;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(indeg[x*n+y]==0)q.push({x,y});
            }
        }
        int longest_path = 0;
        while(!q.empty()){
            longest_path++;
            int sz = q.size();
            while(sz--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int new_x = x + dx[k];
                    int new_y = y + dy[k];
                    if(!isValid(new_x, new_y, m, n) || mat[x][y] >= mat[new_x][new_y])continue;
                    if(--indeg[new_x*n + new_y] == 0){
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        return longest_path;
    }
};