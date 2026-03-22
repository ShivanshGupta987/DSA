class Solution {
    // TC : O(3*M*M)
    // SC : O(M*M)
    bool rotate_by_90_and_check(vector<vector<int>>& mat, vector<vector<int>>& target){
        int m = mat.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int j=0;j<m;j++){
            int l = 0, r = m-1;
            while(l<r){
                swap(mat[l][j], mat[r][j]);
                l++, r--;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> mat_copy  = mat;
        for(int i=0;i<4;i++){
            if(rotate_by_90_and_check(mat_copy, target)) return true;
        }
        return false;
    }
};