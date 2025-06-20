class Solution {
    // TC : O(N)
    // SC : O(1)
    int solve(string &s, int k, int char1, int char2){
        int cur = 0;
        int maxx = 0;
        for(int i=0;s[i];i++){
            if(s[i]==char1 || s[i]==char2){
                cur++;
            }
            else{
                if(k>0){
                    cur++;
                    k--;
                }
                else cur--;
            }
            maxx = max(maxx, cur);
        }
        return maxx;
    }
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        ans = max(ans, solve(s, k, 'N', 'E'));
        ans = max(ans, solve(s, k, 'N', 'W'));
        ans = max(ans, solve(s, k, 'S', 'E'));
        ans = max(ans, solve(s, k, 'S', 'W'));
        
        return ans;
    }
};