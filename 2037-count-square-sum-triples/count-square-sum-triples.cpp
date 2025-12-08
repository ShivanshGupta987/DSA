class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                int c2 = i*i + j*j;
                int t = sqrt(c2);
                if(t<=n && t*t==c2) cnt++;
            }
        }
        return cnt;
    }
};