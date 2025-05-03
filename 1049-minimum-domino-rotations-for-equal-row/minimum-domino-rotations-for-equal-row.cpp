class Solution {
// TC : O(N)
// SC : O(1)
    
int solve(vector<int>& tops, vector<int>& bottoms, int num ){
    int n = tops.size();
    int rot_cnt = 0; // cnt for rotating from bottom to top
    bool isPossible = true;
    int ans = n;
    for(int i=0;i<n;i++){
        if(bottoms[i] != num && tops[i]!=num) {
            isPossible = false; break;
        }
        if(tops[i]!=num && bottoms[i]==num) rot_cnt++;
    }
    // cout<<rot_cnt<<" ";
    if(isPossible){
        ans = min(ans, rot_cnt);
        ans = min(ans, n-rot_cnt);
        // cout<<"("<<num<<","<<rot_cnt<<") ";
    }
    return isPossible? ans : -1;
}
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int n = tops.size();
        int ans = n;
        bool global_possible = false;
        for(int num=1; num<=6; num++){
            int res1 = solve(tops, bottoms, num);
            if(res1!=-1){
                global_possible = true;
                ans = min(ans, res1);
            }
            int res2 = solve(bottoms, tops, num);
            if(res2!=-1){
                global_possible = true;
                ans = min(ans, res2);
            }
            
        }
        if(global_possible) return  ans;
        else return -1;
        
    }
};