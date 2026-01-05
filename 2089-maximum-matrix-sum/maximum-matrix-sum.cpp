class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        bool isNeg = false;
        int m = mat.size(), n = mat[0].size();
        int sm = 1e6;
        long long total_sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sm = min(abs(mat[i][j]), sm);
                if(mat[i][j]<0) isNeg = !isNeg;
                total_sum += abs(mat[i][j]);
            }
        }
        if(isNeg) total_sum -= 2*sm;
        return total_sum;
    }
};